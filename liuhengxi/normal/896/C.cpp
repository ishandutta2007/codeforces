#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e5+5,MOD=1000000007;
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
struct node
{
	int l,r;
	mutable long long v;
	friend bool operator<(node a,node b){return a.l<b.l;}
};
int pow(int aa,int b,int p)
{
	long long a=aa,c=1;
	for(;b;b>>=1,(a*=a)%=p)if(b&1)(c*=a)%=p;
	return (int)c;
}
int n,m,seed,vmax,a[N];
set<node> odt;
int rnd()
{
	int ret=seed;
	seed=(int)((seed*7ll+13)%MOD);
	return ret;
}
auto split(int x)
{
	auto iter=odt.upper_bound(node({x,x,0}));--iter;
	if(iter->l==x)return iter;
	node tmp=*iter;
	odt.erase(iter);
	odt.insert(node({tmp.l,x,tmp.v}));
	return odt.insert(node({x,tmp.r,tmp.v})).first;
}
void assign(int l,int r,long long v)
{
	auto ir=split(r);
	auto il=split(l);
	odt.erase(il,ir);
	odt.insert(node({l,r,v}));
}
void add(int l,int r,long long v)
{
	auto ir=split(r);
	auto il=split(l);
	for(auto i=il;i!=ir;++i)i->v+=v;
}
int main()
{
	read(n,m,seed,vmax);
	F(i,0,n)a[i]=rnd()%vmax+1,odt.insert(node({i,i+1,a[i]}));
	while(m--)
	{
		int opt=rnd()%4+1,l,r,x,y;
		l=rnd()%n;r=rnd()%n;
		if(l>r)swap(l,r);
		++r;
		if(opt==3)x=rnd()%(r-l);
		else x=rnd()%vmax+1;
		if(opt==4)y=rnd()%vmax+1;
		if(opt==1)
		{
			add(l,r,x);
		}
		if(opt==2)
		{
			assign(l,r,x);
		}
		if(opt==3)
		{
			auto ir=split(r);
			auto il=split(l);
			long long ans=0;
			vector<node> vec;
			for(auto i=il;i!=ir;++i)vec.push_back(*i);
			sort(vec.begin(),vec.end(),[](node c,node d){return c.v<d.v;});
			for(node e:vec)
			{
				if(x<e.r-e.l)
				{
					ans=e.v;
					break;
				}
				x-=e.r-e.l;
			}
			printf("%lld\n",ans);
		}
		if(opt==4)
		{
			auto ir=split(r);
			auto il=split(l);
			long long ans=0;
			for(auto i=il;i!=ir;++i)
			{
				ans+=(long long)(i->r-i->l)*pow((int)(i->v%y),x,y)%y;
			}
			printf("%lld\n",ans%=y);
		}
	}
	return 0;
}