#include<cstdio>
#include<utility>
#include<vector>
#include<unordered_set>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
typedef pair<int,int> pii;
const int N=1e5+5;
template<typename T>void readmain(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
template<typename T>T& read(T &x){readmain(x);return x;}
template<typename T,typename ...Tr>void read(T &x,Tr&... r){readmain(x);read(r...);}
struct custom_hash
{
	size_t operator()(pii x)const
	{return (x.first+x.second*371627ll)%28885858847;}
};
int tt,n,m,k,deg[N],d[N],q[N],qf,qr,t[N],tl,u[N],v[N];
vector<int> e[N];
unordered_set<pii,custom_hash> s;
int main()
{
	for(read(tt);tt--;)
	{
		read(n,m,k);
		F(i,0,n)deg[i]=0;
		F(i,0,m)
		{
			--read(u[i]);--read(v[i]);
			e[u[i]].push_back(v[i]),e[v[i]].push_back(u[i]);
			++deg[u[i]],++deg[v[i]];
			s.insert(make_pair(u[i],v[i]));
			s.insert(make_pair(v[i],u[i]));
		}
		qf=qr=0;
		F(i,0,n)if((d[i]=deg[i])<k)q[qr++]=i;
		while(qf<qr)
		{
			int u=q[qf++];
			for(int v:e[u])if(--d[v]==k-1)q[qr++]=v;
		}
		if(qr==n)
		{
			bool found=false;
			qf=qr=0;
			F(i,0,n)if((d[i]=deg[i])<k-1)q[qr++]=i;
			while(qf<qr)
			{
				int u=q[qf++];
				d[u]=-1;
				for(int v:e[u])if(--d[v]==k-2)q[qr++]=v;
			}
			F(i,0,n)if(d[i]==k-1)q[qr++]=i;
			while(qf<qr)
			{
				int u=q[qf++];
				bool ok=true;
				tl=0;
				d[u]=-1;
				for(int v:e[u])if(d[v]>=k-1)t[tl++]=v;
				if(tl==k-1)
				{
					F(i,0,k-1)F(j,0,i)ok=ok&&s.count(make_pair(t[i],t[j]));
					if(ok)
					{
						puts("2");
						F(i,0,k-1)printf("%d ",t[i]+1);
						printf("%d\n",u+1);
						found=true;
						break;
					}
				}
				for(int v:e[u])if(--d[v]==k-1)q[qr++]=v;
			}
			if(!found)puts("-1");
		}
		else
		{
			printf("1 %d\n",n-qr);
			F(i,0,n)if(d[i]>=k)printf("%d ",i+1);
			puts("");
		}
		F(i,0,n)e[i].clear();
		F(i,0,m)s.erase(make_pair(u[i],v[i])),s.erase(make_pair(v[i],u[i]));
	}
	return 0;
}