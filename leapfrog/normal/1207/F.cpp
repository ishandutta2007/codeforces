//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}/*}}}*/
int m,a[500005],vl[708][708],C=707;
int main()
{
	read(m);for(int i=1;i<=m;i++)
	{
		int fg,x,b;read(fg),read(x),read(b);
		if(fg==2&&x<C) {printf("%d\n",vl[x][b]);continue;}
		if(fg==1) {a[x]+=b;for(int i=1;i<C;i++) vl[i][x%i]+=b;}
		else {int rs=0;for(int i=b;i<=500000;i+=x) rs+=a[i];printf("%d\n",rs);}
	}
	return 0;
}