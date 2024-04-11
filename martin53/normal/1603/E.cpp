//Only inp[1]*inp[i]>=inp[1]+...+inp[n] matters
#include<bits/stdc++.h>
using namespace std;

const int nmax=2e2+5;

long long OUTP=0;

int n,m;

int inp[nmax];

int c[nmax][nmax];

int states=0;

vector< pair< pair<int/*sum*/,int/*position*/>,int/*value*/> > dp[nmax],help;

void extend(int sum,int prv,int pos,long long coeff)
{
    if(pos==n)
    {
        OUTP=(OUTP+coeff)%m;
        return;
    }

    if(prv==n+1)return;

    if(inp[1]*(n+1)<sum+(n-pos)*(prv+1))return;

    states++;

    dp[prv+1].push_back({{sum,pos},coeff});

    int new_val=prv+1;

    int sum_new=sum;

    for(int pos_now=1;pos_now+pos<=n;pos_now++)
    {
        sum_new+=new_val;

        if(sum_new>inp[1]*new_val)break;

        //long long cur=rec(sum_new,new_val,pos+pos_now)*c[n-pos][pos_now];
        dp[new_val].push_back({{sum_new,pos+pos_now},coeff*c[n-pos][pos_now]%m});
    }
}

int main()
{
    scanf("%i%i",&n,&m);

    if(n==1)
    {
        printf("%i\n",2%m);
        return 0;
    }

    for(int i=0;i<nmax;i++)
        for(int j=0;j<=i;j++)
            if(j==0||j==i)c[i][j]=1;
            else c[i][j]=(c[i-1][j]+c[i-1][j-1])%m;

    //P(1,j) => j<=inp[j]
    int low=1;

    while(1)//Repeatedly apply inp[i]>=max(c,i) and P(1,n): inp[1]*inp[n]>=c+c+...+c+(c+1)+...+(n-1)+inp[n] and inp[n]<=n+1
    {
        int up=2*(n+1+low*low)+(n+low)*(n-1-low);

        int down=2*(n+1);

        int low_new=(up+down-1)/down;

        if(low<low_new)low=low_new;
        else break;
    }

    for(inp[1]=low;inp[1]<=n+1;inp[1]++)
    {
        for(int j=1;j<=n+1;j++)dp[j]={};

        for(int t=1;t<=inp[1]&&t<=n;t++)
        {
            dp[inp[1]].push_back({{inp[1]*t,t},c[n][t]});
        }

        for(int prv=inp[1];prv<=n+1;prv++)
        {
            sort(dp[prv].begin(),dp[prv].end());

            help={};
            for(auto w:dp[prv])
                if(help.size()&&help.back().first==w.first)help.back().second=(help.back().second+w.second)%m;
                else help.push_back(w);

            dp[prv]={};
            dp[prv].shrink_to_fit();

            for(auto w:help)
                extend(w.first.first,prv,w.first.second,w.second);
        }
    }

    printf("%i\n",OUTP);

    return 0;
}