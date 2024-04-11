#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>
#include<utility>
using namespace std;
typedef long long LL;
const int MAXN=200010;
map<int,int> M1,M2;
map<pair<int,int>,int> M3;
int n,x[MAXN],y[MAXN];
LL ans;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d%d",&x[i],&y[i]),M1[x[i]]++,M2[y[i]]++,M3[make_pair(x[i],y[i])]++;
    for(map<int,int>::iterator it=M1.begin();it!=M1.end();++it) ans+=(LL)(it->second)*(it->second-1)/2;
    for(map<int,int>::iterator it=M2.begin();it!=M2.end();++it) ans+=(LL)(it->second)*(it->second-1)/2;
    for(map<pair<int,int>,int>::iterator it=M3.begin();it!=M3.end();++it) ans-=(LL)(it->second)*(it->second-1)/2;
    printf("%I64d\n",ans);
    return 0;
}