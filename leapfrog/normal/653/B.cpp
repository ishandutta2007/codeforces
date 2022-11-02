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
int n,q,ds[15][15];ll rs[15],tp[15];char a[5],b[5];
int main()
{
	read(q,n),q--;for(int i=1;i<=n;i++)
		scanf("%s%s",a,b),ds[*b-'a'][*a-'a']++;
	rs[0]=1;for(int i=1;i<=q;i++)
	{
		for(int j=0;j<6;j++) tp[j]=0;
		for(int a=0;a<6;a++) for(int b=0;b<6;b++) tp[b]+=rs[a]*ds[a][b];
		for(int j=0;j<6;j++) rs[j]=tp[j];
	}
	ll as=0;for(int i=0;i<6;i++) as+=rs[i];
	return printf("%lld\n",as),0;
}