//Coded by Kamiyama_Shiki on 2021.11.16 {{{
//
#include<bits/stdc++.h>
#define debug(...) fprintf(stderr,__VA_ARGS__)
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}//}}}
const int N=100005;vector<int>v[2];int n,a[N];
int main()
{
	read(n);for(int i=1;i<=n;i++) read(a[i]),v[a[i]&1].push_back(a[i]);
	sort(v[0].begin(),v[0].end()),sort(v[1].begin(),v[1].end());
	ll rs=0;for(auto x:v[1]) rs+=x;
	if(v[1].empty()) return puts("0"),0;else for(auto x:v[0]) rs+=x;
	if(v[1].size()%2==0) rs-=v[1][0];
	return printf("%lld\n",rs),0;
}