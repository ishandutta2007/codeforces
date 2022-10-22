#include<cstdio>
#include<queue>
#include<algorithm>
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
constexpr int N=1e5+5;
struct qy
{
	int id,x,y;
	friend bool operator<(qy a,qy b){return a.x-a.y>b.x-b.y;}
}q[N];
int n,a[N],s[N],m;
deque<pair<int,int>> c[(1<<18)+5];
#define lc (p<<1)
#define rc (p<<1|1)
#define x first
#define y second
bool chk(pair<int,int> u,pair<int,int> v,pair<int,int> w)
{
	return (long long)(v.x-u.x)*(w.y-v.y)<=(long long)(w.x-v.x)*(v.y-u.y);
}
int eval(pair<int,int> u,int v){return u.x*v+u.y;}
#undef x
#undef y
void build(int p,int l,int r)
{
	if(r-l==1)return c[p].emplace_back(a[l],l*a[l]-s[l]);
	int mid=(l+r)>>1;
	build(lc,l,mid);build(rc,mid,r);
	for(auto i=c[lc].cbegin(),j=c[rc].cbegin(),ei=c[lc].cend(),ej=c[rc].cend();i!=ei||j!=ej;)
	{
		auto np=*(i!=ei&&(j==ej||i->first<j->first)?i:j)++;
		if(!c[p].empty()&&(--c[p].end())->first==np.first)
		{
			if((--c[p].end())->second<=np.second)continue;
			c[p].pop_back();
		}
		while(c[p].size()>=2&&chk(*----c[p].end(),*--c[p].end(),np))c[p].pop_back();
		c[p].emplace_back(np);
	}
}
int query(int p,int l,int r,int x,int y,int v)
{
	if(x==l&&r==y)
	{
		while(c[p].size()>1&&eval(*++c[p].cbegin(),v)<=eval(*c[p].cbegin(),v))c[p].pop_front();
		return eval(*c[p].begin(),v);
	}
	int mid=(l+r)>>1;
	if(y<=mid)return query(lc,l,mid,x,y,v);
	if(mid<=x)return query(rc,mid,r,x,y,v);
	return min(query(lc,l,mid,x,mid,v),query(rc,mid,r,mid,y,v));
}
#undef lc
#undef rc
int ans[N];
int main()
{
	F(i,0,read(n))s[i+1]=s[i]+=read(a[i]);
	F(i,0,read(m))read(q[i].x),--read(q[i].y),q[i].id=i;
	build(1,0,n);
	sort(q,q+m);
	F(i,0,m)ans[q[i].id]=query(1,0,n,q[i].y-q[i].x+1,q[i].y+1,q[i].x-q[i].y)+s[q[i].y];
	F(i,0,m)printf("%d\n",ans[i]);
	return 0;
}