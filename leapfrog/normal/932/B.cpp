#include<bits/stdc++.h>//{{{
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
    x=0;char c=getchar(),f=0;
    for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
    for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
    f?x=-x:x;
}
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}/*}}}*/
const int N=1000005;int Q,G[N];vector<int>v[10];
inline int F(int x) {int r=1;for(;x;x/=10) if(x%10) r*=x%10;return r;}
inline int lb(int x,int k) {return upper_bound(v[k].begin(),v[k].end(),x)-v[k].begin();}
int main()
{
	for(int i=1;i<10;i++) G[i]=i;
	for(int i=10;i<N;i++) G[i]=G[F(i)];
	for(int i=1;i<N;i++) v[G[i]].push_back(i);
	read(Q);for(int l,r,k;Q--;) read(l,r,k),printf("%d\n",lb(r,k)-lb(l-1,k));
	return 0;
}