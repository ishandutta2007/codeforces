//Coded by Kamiyama_Shiki on 2021.11.10 {{{
//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}//}}}
const int N=400005;
pair<ll,int>p[N];int n,pt;ll rs[N];
int main()
{
	read(n);for(int i=1;i<=n;i++) {ll l,r;read(l,r),p[++pt]=make_pair(l,1),p[++pt]=make_pair(r+1,-1);}
	sort(p+1,p+pt+1);for(int i=1,k=0;i<=pt;i++) rs[k]+=p[i].first-p[i-1].first,k+=p[i].second;
	for(int i=1;i<=n;i++) printf("%lld%c",rs[i],i==n?'\n':' ');
	return 0;
}