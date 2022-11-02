//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),bz=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) bz=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	bz?x=-x:x;
}/*}}}*/
struct node{int l,r,id;char operator<(node b) const {return r^b.r?r>b.r:id<b.id;}}a[200005];
int n,K,rs[200005],rt;vector<int>sl[200005],sr[200005];set<node>st;
int main()
{
	read(n),read(K);for(int i=1;i<=n;i++) read(a[i].l),read(a[i].r),a[i].id=i;
	for(int i=1;i<=n;i++) sl[a[i].l].push_back(i),sr[a[i].r].push_back(i);
	for(int i=1;i<=200000;i++)
	{
		for(auto x:sl[i]) st.insert(a[x]);
		//{for(auto x:st) printf("<%d,%d,%d> ",x.l,x.r,x.id);putchar('\n');}
		while((int)st.size()>K) rs[++rt]=st.begin()->id,st.erase(st.begin());
		//{for(auto x:st) printf("<%d,%d,%d> ",x.l,x.r,x.id);putchar('\n'),putchar('\n');}
		for(auto x:sr[i]) if(st.find(a[x])!=st.end()) st.erase(st.find(a[x]));
	}
	printf("%d\n",rt);for(int i=1;i<=rt;i++) printf("%d%c",rs[i],i==rt?'\n':' ');
	return 0;
}