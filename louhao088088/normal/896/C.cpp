#include<bits/stdc++.h>
using namespace std;
#define rank asfdsfsdtgewtewt
#define int long long
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
int n,m,seed,vmax,a[maxn],op,l,r,x,y;
int rnd()
{
	int ret=seed;
	seed=(seed*7+13)%1000000007;
	return ret;
}
struct node
{
	int l,r;mutable int v;
	node(int L,int R=0,int V=0):l(L),r(R),v(V){}
	bool operator < (const node &a)const{return l<a.l;}
};
struct rank
{
	int num,v;
	rank();
	rank(int L,int R,int V):num(R-L+1),v(V){}
	bool operator < (const rank &a)const{return v<a.v;}
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
int Pow(int x,int y,int mod){int res=1;x=x%mod;while(y){if(y&1)res=res*x%mod;x=x*x%mod;y=y>>1ll;}return res;}
void assign(int l,int r,int num)
{
	set<node>::iterator itr=split(r+1),itl=split(l);
	//cout<<itl->l<<" "<<itr->l<<endl;
	s.erase(itl,itr);s.insert(node(l,r,num));
}
void add(int l,int r,int num)
{
	set<node>::iterator itr=split(r+1),itl=split(l),it;
	for(it=itl;it!=itr&&it!=s.end();it++)
		it->v+=num;
}
int getkth(int l,int r,int k)
{
	set<node>::iterator itr=split(r+1),itl=split(l),it;
	vector<rank>c;c.clear();
	for(it=itl;it!=itr&&it!=s.end();it++)
		c.push_back(rank(it->l,it->r,it->v));
	sort(c.begin(),c.end());
	for(int i=0;i<(int)c.size();i++)
		if(k<=c[i].num)return c[i].v;
		else k-=c[i].num;
}
int getans(int l,int r,int x,int mod)
{
	int res=0;
	set<node>::iterator itr=split(r+1),itl=split(l),it;
	for(it=itl;it!=itr&&it!=s.end();it++)res=(res+((it->r-it->l+1)%mod)*Pow(it->v,x,mod))%mod;
	return res;
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read(),m=read(),seed=read(),vmax=read();
	for(int i=1;i<=n;i++)
	    a[i]=(rnd()%vmax)+1,s.insert(node(i,i,a[i]));
		//cout<<a[i]<<" ";cout<<endl;
	for(int i=1;i<=m;i++)
	{
	    op=(rnd()%4)+1;
	    l=(rnd()%n)+1;r=(rnd()%n)+1;
	    if(l>r)swap(l,r);
	    if(op==3)x=(rnd()%(r-l+1))+1;
	    else x=(rnd()%vmax)+1;
	    if(op==4)y=(rnd()%vmax)+1;
	    //cout<<op<<" "<<l<<" "<<r<<" "<<x<<" "<<y<<endl;
	    if(op==1)add(l,r,x);
	    if(op==2)assign(l,r,x);
	    if(op==3)printf("%lld \n",getkth(l,r,x));
	    if(op==4)printf("%lld \n",getans(l,r,x,y));
	}
	
		return 0;
}