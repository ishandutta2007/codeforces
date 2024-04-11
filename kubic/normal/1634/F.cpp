#include <bits/stdc++.h>
using namespace std;
#define N 300005
#define LIM 1000005
#define mid ((l+r)/2)
#define gc() (P1==P2 && (P2=(P1=buf)+fread(buf,1,LIM,stdin),P1==P2)?EOF:*P1++)
char *P1,*P2,buf[LIM];
int n,m,MOD,a[N],fib[N];
int add(int x,int y) {x+=y;return x<MOD?x:x-MOD;}
int rd()
{
	int res=0;char c=0;while(!isdigit(c)) c=gc();
	while(isdigit(c)) res=res*10+c-48,c=gc();return res;
}
char rd1() {char c=0;while(!isalpha(c)) c=gc();return c;}
struct Node
{
	int x,y;Node(int _x=0,int _y=0) {x=_x;y=_y;}
	bool operator == (Node t) const
	{return (x==-2 || t.x==-2 || x==t.x) && y==t.y;}
	Node operator + (Node t) const
	{return Node((x==-2 || t.x==-2?-2:add(x,t.x)),add(y,t.y));}
	Node operator += (Node t) {return (*this)=(*this)+t;}
	Node f(int w)
	{
		if(w==1) return *this;int t1=fib[w-2],t2=fib[w-1],t3=fib[w];
		return Node((1ll*x*t1+1ll*y*t2)%MOD,(1ll*x*t2+1ll*y*t3)%MOD);
	}
};
struct Seg {Node tg,vl;}sg[N*4];
void pu(int p,int l,int r)
{
	if(sg[p*2].vl.x==-1 || sg[p*2+1].vl.x==-1) {sg[p].vl=Node(-1,-1);return;}
	if(sg[p*2].vl.x==-2 && sg[p*2+1].vl.x==-2)
	{sg[p].vl=(Node) {add(sg[p*2+1].vl.y,MOD-sg[p*2].vl.y),sg[p*2].vl.y};}
	else sg[p].vl=sg[p*2].vl.f(mid-l+2)==sg[p*2+1].vl?sg[p*2].vl:Node(-1,-1);
}
void mdf(int p,Node vl) {sg[p].tg+=vl;if(~sg[p].vl.x) sg[p].vl+=vl;}
void pd(int p,int l,int r)
{
	if(sg[p].tg.x || sg[p].tg.y)
		mdf(p*2,sg[p].tg),mdf(p*2+1,sg[p].tg.f(mid-l+2)),sg[p].tg=Node(0,0);
}
void build(int p,int l,int r)
{
	if(l==r) {sg[p].vl=Node(-2,a[l]);return;}
	build(p*2,l,mid);build(p*2+1,mid+1,r);pu(p,l,r);
}
void upd(int p,int l,int r,int qL,int qR,Node vl)
{
	if(l>=qL && r<=qR) {mdf(p,vl.f(l-qL+1));return;}pd(p,l,r);
	if(qL<=mid) upd(p*2,l,mid,qL,qR,vl);
	if(qR>mid) upd(p*2+1,mid+1,r,qL,qR,vl);pu(p,l,r);
}
int main()
{
	n=rd();m=rd();MOD=rd();fib[1]=1;
	for(int i=2;i<=n;++i) fib[i]=add(fib[i-1],fib[i-2]);
	for(int i=1;i<=n;++i) a[i]=rd();
	for(int i=1,x;i<=n;++i) x=rd(),a[i]=add(a[i],MOD-x);
	build(1,1,n);
	for(int i=1,l,r;i<=m;++i)
	{
		char op;op=rd1();l=rd();r=rd();
		if(op=='A') upd(1,1,n,l,r,Node(0,1));
		if(op=='B') upd(1,1,n,l,r,Node(0,MOD-1));
		puts((!sg[1].vl.x || sg[1].vl.x==-2) && !sg[1].vl.y?"YES":"NO");
	}return 0;
}