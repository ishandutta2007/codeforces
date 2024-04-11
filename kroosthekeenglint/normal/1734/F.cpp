#include<set>
#include<map>
#include<list>
#include<queue>
#include<stack>
#include<string>
#include<math.h>
#include<time.h>
#include<vector>
#include<bitset>
#include<memory>
#include<utility>
#include<fstream>
#include<stdio.h>
#include<sstream>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
map<pair<long long,long long>,long long> ma;
bool try_count(long long x)
{
    bool ans = 0;
    for (;x;x>>=1)
    {
        ans ^= (x&1);
    }
    return ans;
}
long long dfs(long long n,long long m)
{
    if (m == 0)
    {
        return 0;
    }
    if (ma.find(make_pair(n,m)) != ma.end())
    {
        return ma[make_pair(n,m)];
    }
    int cnt = 0;
    if (m % 2 == 1)
    {
        cnt = try_count((n+m-1)^(m-1));
    }
    if (n%2 == 0)
    {
        ma[make_pair(n,m)] = dfs(n>>1, m>>1) * 2 + cnt;
        return ma[make_pair(n,m)];
    }
    else
    {
        long long val = dfs(n>>1, m>>1) + dfs((n>>1)+1, m>>1);
        ma[make_pair(n,m)] = (m - (m&1)) - val + cnt;
        return ma[make_pair(n,m)];
    }
}
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int t;
    scanf("%d",&t);
    int zu;
    for (zu=0;zu<t;zu++)
    {
        long long n,m;
        scanf("%lld%lld",&n,&m);
        long long ans = dfs(n,m);
        printf("%lld\n",ans);
    }
    return 0;
}