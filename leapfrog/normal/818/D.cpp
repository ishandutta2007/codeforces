//Coded by Kamiyama_Shiki on 2021.11.12 {{{
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
const int N=100005;
int a[N],n,A;vector<int>v[N*10];
int main()
{
	read(n,A);for(int i=1;i<=n;i++) read(a[i]),v[a[i]].push_back(i);
	for(int i=1;i<=1000000;i++) if(i!=A&&v[i].size()>=v[A].size())
	{
		char fg=1;
		for(size_t j=0;j<v[A].size();j++) if(v[A][j]<v[i][j]) {fg=0;break;}
		if(fg) return printf("%d\n",i),0;
	}return puts("-1"),0;
}