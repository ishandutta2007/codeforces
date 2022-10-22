#include<cstdio>
#include<algorithm>
#include<random>
#include<chrono>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
template<typename T>void readmain(T &x)
{
	bool neg=false;
	unsigned int c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
template<typename T>T& read(T &x){readmain(x);return x;}
template<typename T,typename ...Tr>void read(T &x,Tr&... r){readmain(x);read(r...);}
constexpr int N=2e5+5;
namespace treap
{
#ifndef LOCAL
	mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
#else
	mt19937 rnd(1233123312331233123);
#endif
	struct node
	{
		int val,tag,ans,at,qid,pr,son[2];
	}s[N<<5];
#define val(x) s[x].val
#define tag(x) s[x].tag
#define ans(x) s[x].ans
#define at(x) s[x].at
#define qid(x) s[x].qid
#define pr(x) s[x].pr
#define son(x) s[x].son
#define real(x) ((long long)val(x)<<32|qid(x))
	int ind;
	int newnode(int v,int q){int p=++ind;val(p)=v;qid(p)=q;pr(p)=(int)rnd();return p;}
	inline void add(int p,int v,int a){val(p)+=v,tag(p)+=v,ans(p)+=a,at(p)+=a;}
	inline void pushdown(int p)
	{
		if(!tag(p))return;
		add(son(p)[0],tag(p),at(p));
		add(son(p)[1],tag(p),at(p));
		tag(p)=at(p)=0;
	}
	int merge(int p1,int p2)
	{
		if(!(p1&&p2))return p1|p2;
		if(pr(p1)>pr(p2))
		{
			pushdown(p1);
			son(p1)[1]=merge(son(p1)[1],p2);
			return p1;
		}
		else
		{
			pushdown(p2);
			son(p2)[0]=merge(p1,son(p2)[0]);
			return p2;
		}
	}
	void split(int p,long long v,int &p1,int &p2)
	{
		if(!p)return p1=p2=0,void();
		pushdown(p);
		if(real(p)<v)split(son(p)[1],v,son(p1=p)[1],p2);
		else split(son(p)[0],v,p1,son(p2=p)[0]);
	}
	int insert(int p,int v)
	{
		int p1,p2;
		split(p,real(v),p1,p2);
		return merge(p1,merge(v,p2));
	}
	void dfs(int p,void f(node))
	{
		if(!p)return;
		if(p)f(s[p]);
		pushdown(p);
		dfs(son(p)[0],f);
		dfs(son(p)[1],f);
	}
#undef val
#undef tag
#undef ans
#undef at
#undef qid
#undef pr
#undef son
}
using treap::newnode;
using treap::add;
using treap::merge;
using treap::split;
using treap::insert;
using treap::dfs;
int n,c[N],q[N],id[N],m,b[N],ans[N];
int p1,p23,p2,p3;
int cc;
void sub(treap::node x){p1=insert(p1,newnode(x.val-cc,x.qid));ans[x.qid]+=x.ans+1;}
void fi(treap::node x){ans[x.qid]+=x.ans;}
int main()
{
	read(n);
	F(i,0,n)read(c[i],q[i]),id[i]=i;
	sort(id,id+n,[](int u,int v){return q[u]==q[v]?c[u]<c[v]:q[u]>q[v];});
	read(m);
	int u=0;
	F(i,0,m)read(b[i]),u=insert(u,newnode(b[i],i));
	F(i,0,n)
	{
		cc=c[id[i]];
		split(u,(long long)cc<<32,p1,p23);
		split(p23,(long long)cc<<33,p2,p3);
		dfs(p2,sub);
		add(p3,-cc,1);
		u=merge(p1,p3);
	}
	dfs(u,fi);
	F(i,0,m)printf("%d ",ans[i]);
	puts("");
	return 0;
}