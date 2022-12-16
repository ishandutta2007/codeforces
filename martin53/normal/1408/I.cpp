#include<bits/stdc++.h>
using namespace std;

const int nmax=(1<<16)+42,mod=998244353;

int n,k,c;

int inp[nmax];

int C[20][20];

long long dp[17][nmax];//count the number of ways : used numbers, xor value

long long outp[nmax];

long long my_pow(long long a,int b)
{
    long long ret=1;

    while(b)
    {
        if(b%2)ret=ret*a%mod;
        b=b/2;
        a=a*a%mod;
    }
    return ret;
}

int mx_diff[nmax];

pair<int,int> order[nmax];

int main()
{
    scanf("%i%i%i",&n,&k,&c);

    for(int i=0;i<=k;i++)
        for(int j=0;j<=i;j++)
            if(j==0||j==i)C[i][j]=1;
            else C[i][j]=C[i-1][j]+C[i-1][j-1];

    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=k;j++)
            mx_diff[i]=max(mx_diff[i],inp[i]^(inp[i]-j));
    }

    for(int i=1;i<=n;i++)
        order[i]={mx_diff[i],i};

    sort(order+1,order+n+1);

    int all=0;
    for(int i=1;i<=n;i++)all=all^inp[i];

    dp[0][0]=1;

    for(int t=1;t<=n;t++)
    {
        int cur_i=order[t].second;

        int sz=0;

        while((1<<sz)<=mx_diff[cur_i])sz++;

        for(int used=k;used>=0;used--)
            for(int cur=1;cur<=used;cur++)
            {
                int to_shift=inp[cur_i]^(inp[cur_i]-cur);

                for(int num=0;num<(1<<sz);num++)
                {
                    //cout<<i<<" "<<num<<" "<<used<<" "<<cur<<" "<<to_shift<<dp[!(i%2)][num^to_shift][used-cur]<<" "<<C[k-(used-cur)][cur]<<endl;

                    dp[used][num]=(dp[used][num]+dp[used-cur][num^to_shift]*C[k-(used-cur)][cur]);
                }

                //if(dp[num][used])cout<<num<<" "<<used<<" "<<dp[num][used]<<endl;

                //cout<<"---"<<endl;
            }

        for(int used=0;used<=k;used++)
            for(int num=0;num<(1<<sz);num++)
                dp[used][num]=dp[used][num]%mod;

    }

    //divide by n^k

    long long help=my_pow(n,mod-2);
    help=my_pow(help,k);

    for(int i=0;i<(1<<c);i++)
    {
        outp[i]=dp[k][i^all];

        outp[i]=outp[i]*help%mod;
    }

    for(int i=0;i<(1<<c);i++)
        printf("%lld ",outp[i]);

    return 0;
}