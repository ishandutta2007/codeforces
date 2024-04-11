#include<bits/stdc++.h>
using namespace std;

const int nmax=50+4;

int n;
long long a[nmax],b[nmax];

pair<long long/*gain*/,int/*a*/> help[nmax];

bool cmp(pair<long long/*gain*/,int/*a*/> x,pair<long long/*gain*/,int/*a*/> y)
{
    return x.second>y.second;
}

bool solved[nmax][nmax][nmax];
long long dp[nmax][nmax][nmax];

long long rec(int pos,int free_bigger,int free_equal)
{
    if(pos>n)return 0;

    if(solved[pos][free_bigger][free_equal])return dp[pos][free_bigger][free_equal];

    long long ret=1e18;

    //take
    if(help[pos].second==help[pos+1].second)ret=min(ret,help[pos].first+rec(pos+1,free_bigger,free_equal+1));
    else ret=min(ret,help[pos].first+rec(pos+1,free_bigger+free_equal+1,0));

    //do not take
    if(help[pos].second==help[pos+1].second)
    {
        if(free_bigger)ret=min(ret,rec(pos+1,free_bigger-1,free_equal));
    }
    else
    {
        if(free_bigger)ret=min(ret,rec(pos+1,free_bigger+free_equal-1,0));
    }

    solved[pos][free_bigger][free_equal]=1;
    dp[pos][free_bigger][free_equal]=ret;

    //cout<<pos<<" "<<free_bigger<<" "<<free_equal<<" -> "<<ret<<endl;

    return ret;
}
long long eval(long long test)
{
    for(int i=1;i<=n;i++)help[i]={a[i]*1000-b[i]*test,a[i]};

    sort(help+1,help+n+1,cmp);

    //for(int i=1;i<=n;i++)cout<<help[i].first<<" "<<help[i].second<<endl;

    memset(solved,0,sizeof(solved));

    //cout<<"test= "<<test<<" -> "<<rec(1,0,0)<<endl;

    return rec(1,0,0);
}

int main()
{
    scanf("%i",&n);
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
    for(int i=1;i<=n;i++)scanf("%lld",&b[i]);

    long long ok=1e8*1000*2+42,not_ok=0;

    while(ok-not_ok>1)
    {
        long long av=(ok+not_ok)/2;

        if(eval(av)<=0)ok=av;
        else not_ok=av;
    }

    //cout<<eval(1160)<<endl;

    printf("%lld\n",ok);

    return 0;
}