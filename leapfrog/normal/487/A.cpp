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
int h1,a1,d1,h2,a2,d2,ch,ca,cd,rs=1e9;
inline int calc(int a1,int d1,int a2,int d2,int h1,int h2)
{int x=(h2+a1-d2-1)/(a1-d2);return max(0,x*max(0,a2-d1)-h1+1);}
int main()
{
	read(h1),read(a1),read(d1),read(h2),read(a2),read(d2),read(ch),read(ca),read(cd);
	for(int i=0;i<=201;i++) for(int j=0;j<=101;j++) if(a1+i>d2) rs=min(rs,ca*i+cd*j+calc(a1+i,d1+j,a2,d2,h1,h2)*ch);
	return printf("%d\n",rs),0;
}