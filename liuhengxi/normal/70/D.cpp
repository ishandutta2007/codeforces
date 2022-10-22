#include<cstdio>
#include<utility>
#include<set>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e5+5,INF=0x3fffffff;
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
int q;
set<pair<int,int>> a,b;
int main()
{
	read(q);
	while(q--)
	{
		int opt,x,y;read(opt,x,y);
		if(opt==1)
		{
			{
			auto it=a.lower_bound({x,-INF});
			bool in;
			if(it==a.end())in=false;
			else if(it->first==x)in=y<=it->second;
			else if(it==a.begin())in=false;
			else
			{
				auto [x1,y1]=*--it;
				auto [x2,y2]=*++it;
				in=(long long)(x1-x)*(y2-y)-(long long)(x2-x)*(y1-y)<=0;
			}
			if(!in)
			{
				if(it!=a.end()&&it->first==x)
				{
					a.erase(*it);
					it=a.emplace(x,y).first;
				}
				else it=a.emplace(x,y).first;
				auto l=it,r=it;
				if(l!=a.begin())
				{
					--l;
					while(l!=a.begin())
					{
						auto [x2,y2]=*--l;
						auto [x1,y1]=*++l;
						if((long long)(x1-x)*(y2-y)-(long long)(x2-x)*(y1-y)>0)break;
						--l;
					}
					++l;
				}
				if(++r!=a.end())
				{
					while((r!=a.end()&&++r!=a.end())||(--r,0))
					{
						auto [x2,y2]=*r;
						auto [x1,y1]=*(--r);
						if((long long)(x1-x)*(y2-y)-(long long)(x2-x)*(y1-y)<0)break;
						++r;
					}
				}
				a.erase(l,it);
				a.erase(++it,r);
			}
			}
			{
			auto it=b.lower_bound({x,-INF});
			bool in;
			if(it==b.end())in=false;
			else if(it->first==x)in=y>=it->second;
			else if(it==b.begin())in=false;
			else
			{
				auto [x1,y1]=*--it;
				auto [x2,y2]=*++it;
				in=(long long)(x1-x)*(y2-y)-(long long)(x2-x)*(y1-y)>=0;
			}
			if(!in)
			{
				if(it!=b.end()&&it->first==x)
				{
					b.erase(*it);
					it=b.emplace(x,y).first;
				}
				else it=b.emplace(x,y).first;
				auto l=it,r=it;
				if(l!=b.begin())
				{
					--l;
					while(l!=b.begin())
					{
						auto [x2,y2]=*--l;
						auto [x1,y1]=*++l;
						if((long long)(x1-x)*(y2-y)-(long long)(x2-x)*(y1-y)<0)break;
						--l;
					}
					++l;
				}
				if(++r!=b.end())
				{
					while((r!=b.end()&&++r!=b.end())||(--r,0))
					{
						auto [x2,y2]=*r;
						auto [x1,y1]=*(--r);
						if((long long)(x1-x)*(y2-y)-(long long)(x2-x)*(y1-y)>0)break;
						++r;
					}
				}
				b.erase(l,it);
				b.erase(++it,r);
			}
			}
		}
		else
		{
			bool in=true;
			auto it=a.lower_bound({x,-INF});
			if(it==a.end())in=false;
			else if(it->first==x)in=in&&y<=it->second;
			else if(it==a.begin())in=false;
			else
			{
				auto [x1,y1]=*--it;
				auto [x2,y2]=*++it;
				in=in&&(long long)(x1-x)*(y2-y)-(long long)(x2-x)*(y1-y)<=0;
			}
			it=b.lower_bound({x,-INF});
			if(it==b.end())in=false;
			else if(it->first==x)in=in&&y>=it->second;
			else if(it==b.begin())in=false;
			else
			{
				auto [x1,y1]=*--it;
				auto [x2,y2]=*++it;
				in=in&&(long long)(x1-x)*(y2-y)-(long long)(x2-x)*(y1-y)>=0;
			}
			puts(in?"YES":"NO");
		}
	}
	return 0;
}