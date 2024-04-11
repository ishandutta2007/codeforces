//{{{
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
inline char cg(int x,int y)
{
	if(x==y) return 1;
	if(x==0) return y==7||y==1;
	if(x==1) return 0;
	if(x==2) return 0;
	if(x==3) return y==1||y==7;
	if(x==4) return y==1;
	if(x==5) return 0;
	if(x==6) return y==5;
	if(x==7) return y==1;
	if(x==8) return 1;
	if(x==9) return y==1||y==3||y==4||y==5||y==7;
	return 0;
}
int main()
{
	int x,rs=0;read(x);
	for(int i=0;i<=99;i++) rs+=cg(i/10,x/10)&&cg(i%10,x%10);
	return printf("%d\n",rs),0;
}