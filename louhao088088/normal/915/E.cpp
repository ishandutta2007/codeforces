#include<bits/stdc++.h>
using namespace std;
#define rank asfdsfsdtgewtewt
static char buf[1000000],*p1=buf,*p2=buf;
//#define getchar() p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++
#define re register
const int maxn=1e5+5;
inline int read()
{
	char ch=getchar();bool f=0;int x=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f==1)x=-x;return x;
}
int n,m,a[maxn],op,l,r,x,y,sum;
struct node
{
	int l,r;mutable int v;
	node(int L,int R=0,int V=0):l(L),r(R),v(V){}
	bool operator < (const node &a)const{return l<a.l;}
};
set<node>s;
set<node>::iterator split(int x)
{
	set<node>::iterator it=s.lower_bound(node(x));
	if(it->l==x&&it!=s.end())return it;
	it--;int l=it->l,r=it->r,v=it->v;
	if(it->r<x)return s.end();s.erase(it);
	s.insert(node(l,x-1,v));
	return s.insert(node(x,r,v)).first;
}
void assign(int l,int r,int num)
{
	set<node>::iterator itr=split(r+1),itl=split(l),it;
	for(it=itl;it!=itr;it++)sum-=(it->v)*(it->r-it->l+1);
	s.erase(itl,itr);s.insert(node(l,r,num));sum+=num*(r-l+1);
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read(),m=read(),
	s.insert(node(1,n,1));sum=n;
		//cout<<a[i]<<" ";cout<<endl;
	for(int i=1;i<=m;i++)
	{
	    l=read(),r=read();op=read();
	    if(op==1)assign(l,r,0);
	    if(op==2)assign(l,r,1);
	    printf("%d\n",sum);
	}
	return 0;
}