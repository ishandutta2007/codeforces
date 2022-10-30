//Coded by leapfrog {{{
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
const int N=200005;
char ch[N];int n,qx[N],qy[N],hx[N],hy[N],px,py,rs;
inline char chk(int ln)
{
	for(int l=1,r=l+ln-1;r<=n;l++,r++)
	{
		int nx=qx[l-1]+hx[r+1],ny=qy[l-1]+hy[r+1];
		int vl=abs(px-nx)+abs(py-ny);
		if((vl&1)==(ln&1)&&vl<=ln) return 1;
	}return 0;
}
int main()
{
	read(n),scanf("%s",ch+1),read(px,py),rs=n+1;
	for(int i=1;i<=n;i++)
	{
		if(ch[i]=='L') qx[i]=hx[i]=-1;else if(ch[i]=='R') qx[i]=hx[i]=1;
		if(ch[i]=='D') qy[i]=hy[i]=-1;else if(ch[i]=='U') qy[i]=hy[i]=1;
	}
	for(int i=1;i<=n;i++) qx[i]+=qx[i-1],qy[i]+=qy[i-1];
	for(int i=n;i>=1;i--) hx[i]+=hx[i+1],hy[i]+=hy[i+1];
	for(int L=0,R=n,md=(L+R)>>1;L<=R;md=(L+R)>>1)
		if(chk(md)) R=md-1,rs=md;else L=md+1;
	return printf("%d\n",rs==n+1?-1:rs),0;
}