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
int n,Q,xj[25],rs[100005],a[100005],tot;vector<pair<int,int> >q[100005];const int P=1e9+7;
inline void ins(int x) {for(int i=20;~i;i--) if((x>>i)&1) {if(!xj[i]) return(void)(tot++,xj[i]=x);else x^=xj[i];}}
inline char que(int x) {for(int i=20;~i;i--) if((x>>i)&1) {if(xj[i]) x^=xj[i];else return 0;}return 1;}
inline int ksm(int x,int q=P-2) {int r=1;for(;q;q>>=1,x=1ll*x*x%P) if(q&1) r=1ll*r*x%P;return r;}
int main()
{
	read(n),read(Q);for(int i=1;i<=n;i++) read(a[i]);
	for(int i=1,l,x;i<=Q;i++) read(l),read(x),q[l].push_back(make_pair(x,i));
	for(int i=1;i<=n;i++)
		{ins(a[i]);for(auto x:q[i]) if(que(x.first)) rs[x.second]=ksm(2,i-tot);}
	for(int i=1;i<=Q;i++) printf("%d\n",rs[i]);
	return 0;
}