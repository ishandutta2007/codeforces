#include<cstdio>
#include<algorithm>
#include<vector>
#define int long long
using std::swap;
using std::vector;
const int N=105;
int pow3[N];
int l,r;
struct cell
{
	int v,k;
};
inline int epc(cell a,cell b)
{
	if(a.v&b.v)
		return 0;
	int ans=1;
	register int i;
	if(a.k<b.k)
		swap(a,b);
	for(i=b.k;i<=a.k-1;i++)
		if(!(b.v>>i&1))
			ans*=2;
	ans*=pow3[b.k];
	return ans;
}
vector<cell> V1,V2;
inline void build(vector<cell> &V,int x)
{
	int cur=0;
	register int i;
	V.clear();
	for(i=60;i>=0;i--)
		if(x>>i&1)
			V.push_back(cell{cur,i}),cur+=1<<i;
	V.push_back(cell{x,0});
	return;
}
inline int calc(int a,int b)
{
	if(a<0||b<0)
		return 0;
	int ans=0;
	build(V1,a);build(V2,b);
	for(cell c1:V1)
		for(cell c2:V2)
			ans+=epc(c1,c2);
	return ans;
}
inline void solve()
{
	scanf("%lld%lld",&l,&r);
	printf("%lld\n",calc(r,r)-2*calc(l-1,r)+calc(l-1,l-1));
	return;
}
signed main()
{
	int T;
	register int i;
	pow3[0]=1;
	for(i=1;i<=80;i++)
		pow3[i]=pow3[i-1]*3;
	scanf("%lld",&T);
	while(T--)
		solve();
	return 0;
}