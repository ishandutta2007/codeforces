#include <bits/stdc++.h>
using namespace std;
#define N 200005
#define EPS 1e-10
#define db double
int n,m,c,a[N],b[N],nw[N];db ans;
struct Node
{
	int x;db vl;
	bool operator < (Node t) const
	{return fabs(vl-t.vl)<EPS?x<t.x:vl>t.vl;}
};multiset<Node> z1,z2;
db calc(int x,int vl=0)
{return 1.0*a[x]*min(nw[x]+vl,b[x])/(min(nw[x]+vl,b[x])+b[x]);}
void ins(int x)
{
	z1.insert((Node) {x,calc(x,1)-calc(x)});
	if(nw[x]) z2.insert((Node) {x,calc(x,-1)-calc(x)});
}
void dlt(int x)
{
	z1.erase((Node) {x,calc(x,1)-calc(x)});
	if(nw[x]) z2.erase((Node) {x,calc(x,-1)-calc(x)});
}
int main()
{
	scanf("%d %d %d",&n,&m,&c);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	for(int i=1;i<=n;++i) scanf("%d",&b[i]),ins(i);
	for(int i=1;i<=m;++i)
	{
		Node t=*z1.begin();ans+=t.vl;
		dlt(t.x);++nw[t.x];ins(t.x);
	}
	for(int i=1,op,x,vl;i<=c;++i)
	{
		scanf("%d %d",&op,&x);vl=op==1?1:-1;
		dlt(x);ans-=calc(x);b[x]+=vl;ins(x);ans+=calc(x);
		while(z1.size() && z2.size())
		{
			Node t1=*z1.begin(),t2=*z2.begin();
			if(t1.vl+t2.vl<EPS) break;
			ans+=t1.vl+t2.vl;dlt(t1.x);dlt(t2.x);
			++nw[t1.x];--nw[t2.x];ins(t1.x);ins(t2.x);
		}printf("%.7lf\n",ans);
	}return 0;
}