#include<set>
#include<map>
#include<deque>
#include<queue>
#include<stack>
#include<cmath>
#include<ctime>
#include<bitset>
#include<string>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<complex>
#include<iostream>
#include<algorithm>
#define ll long long
#define inf 1e9
using namespace std;

inline void down(int &x,const int &y){if(x>y)x=y;}
const int maxn = 110000;

int n,m,a[maxn];
int fa[maxn],s[maxn];
int findfa(const int x){return fa[x]==x?x:fa[x]=findfa(fa[x]);}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) fa[i]=i,s[i]=inf;
	for(int i=1;i<=m;i++)
	{
		int x,y; scanf("%d%d",&x,&y);
		int f1=findfa(x),f2=findfa(y);
		fa[f1]=f2;
	}
	for(int i=1;i<=n;i++) down(s[findfa(i)],a[i]);
	ll ans=0;
	for(int i=1;i<=n;i++) if(findfa(i)==i)
		ans+=(ll)s[i];
	printf("%I64d\n",ans);
	
    return 0;
}