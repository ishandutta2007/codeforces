#include<cstdio>
#include<algorithm>
#include<utility>
#include<vector>
#define int long long
#define mp make_pair
#define fi first
#define se second
using std::lower_bound;
using std::sort;
using std::pair;
using std::mp;
using std::vector;
const int N=1e7+5;
int n,q;
int s[N];
vector<pair<int,int> > V,V2;
signed main()
{
	int x,l,r,ans;
	register int i;
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
		scanf("%lld",&s[i]);
	sort(s+1,s+n+1);
	V.push_back(mp(0,0));
	V2.push_back(mp(0,0));
	V2.push_back(mp(0,1));
	for(i=2;i<=n;i++)
	{
		V2.push_back(mp(0,1));
		V2.push_back(mp(s[i]-s[i-1],-1));
		V.push_back(mp(s[i]-s[i-1],s[i]-s[i-1]));
	}
	sort(V.begin(),V.end());
	sort(V2.begin(),V2.end());
	for(i=1;i<(int)V.size();i++)
		V[i].se+=V[i-1].se;
	for(i=1;i<(int)V2.size();i++)
		V2[i].se+=V2[i-1].se;
	scanf("%lld",&q);
	while(q--)
	{
		scanf("%lld%lld",&l,&r);x=r-l+1;
		ans=(--lower_bound(V.begin(),V.end(),mp(x+1,-0x3f3f3f3f3f3f3f3f)))->se;
		ans+=(--lower_bound(V2.begin(),V2.end(),mp(x+1,-0x3f3f3f3f3f3f3f3f)))->se*x;
		printf("%lld ",ans);
	}
	putchar('\n');
	return 0;
}