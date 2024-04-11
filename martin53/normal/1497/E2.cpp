#include<bits/stdc++.h>
using namespace std;

const int nmax=2e5+42,kmax=25,MX=1e7+42;

int n,k,inp[nmax];

int least[MX];

void prec()
{
    for(int i=1;i<MX;i++)
        least[i]=i;

    for(int p=MX;p;p--)
        if(1LL*p*p<MX)
        {
            for(int j=p*p;j<MX;j+=p*p)
                if(least[j]%(p*p)==0)least[j]=least[j]/p/p;
        }
}

int active[MX];
int cnt_wrong=0;

void add(int val)
{
    if(active[val]>0)cnt_wrong++;

    active[val]++;
}

void sub(int val)
{
    if(active[val]>1)cnt_wrong--;

    active[val]--;
}
int go_back[kmax][nmax];

int dp[kmax][nmax];

int rec(int to_sub,int pos)
{
    if(pos==0)return 0;

    if(dp[to_sub][pos]!=-1)return dp[to_sub][pos];

    int ret=1e9;

    for(int cur=0;cur<=to_sub;cur++)
        ret=min(ret,rec(to_sub-cur,go_back[cur][pos])+1);

    dp[to_sub][pos]=ret;

    return ret;
}
void solve()
{
    scanf("%i%i",&n,&k);

    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    for(int i=1;i<=n;i++)inp[i]=least[inp[i]];

    for(int wrong=0;wrong<=k;wrong++)
    {
        int l=1;

        for(int r=1;r<=n;r++)
        {
            add(inp[r]);

            while(cnt_wrong>wrong)
            {
                sub(inp[l]);
                l++;
            }

            go_back[wrong][r]=l-1;

            //cout<<wrong<<" "<<r<<" -> "<<l<<" "<<cnt_wrong<<endl;
        }

        while(l<=n)
        {
            sub(inp[l]);
            l++;
        }
    }

    for(int i=0;i<=k;i++)
        for(int j=0;j<=n;j++)
            dp[i][j]=-1;

    printf("%i\n",rec(k,n));
}

int main()
{
    prec();

    int t;
    scanf("%i",&t);

    while(t)
    {
        t--;
        solve();
    }

    return 0;
}