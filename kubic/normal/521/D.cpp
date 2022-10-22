#include <bits/stdc++.h>
using namespace std;
#define N 100005
#define ll long long
int n,m,c,cntZ,lim,a[N],d[N],ps[N];
struct Node {int id,w;ll x,y;}z[N];vector<Node> b[N];
bool cmp1(Node x,Node y) {return (x.x-x.y)*y.y>(y.x-y.y)*x.y;}
bool cmp2(Node x,Node y) {return x.w<y.w;}
int main()
{
	scanf("%d %d %d",&n,&m,&c);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	for(int i=1,op,x,vl;i<=m;++i)
	{
		scanf("%d %d %d",&op,&x,&vl);
		if(op==1) {if(vl-a[x]>d[x]) ps[x]=i,d[x]=vl-a[x];}
		if(op==2) b[x].push_back((Node) {i,2,vl,1});
		if(op==3) z[++cntZ]=(Node) {i,3,vl,1};
	}
	for(int i=1;i<=n;++i)
	{
		ll nw=a[i];if(ps[i]) b[i].push_back((Node) {ps[i],1,d[i],1});
		sort(b[i].begin(),b[i].end(),cmp1);
		for(int j=0;j<b[i].size();++j)
		{
			z[++cntZ]=(Node) {b[i][j].id,b[i][j].w,nw+b[i][j].x,nw};
			nw+=b[i][j].x;
		} 
	}lim=min(c,cntZ);sort(z+1,z+cntZ+1,cmp1);sort(z+1,z+lim+1,cmp2);
	printf("%d\n",lim);
	for(int i=1;i<=lim;++i) printf("%d ",z[i].id);return 0;
}