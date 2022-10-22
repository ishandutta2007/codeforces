#include<cstdio>
#include<vector>
#include<set>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=2e5+5;
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
int tt,n,m,a[N],b[N],l[N],r[N],q[N],qf,qr;
long long s[N];
set<int> p;
vector<int> adj[N];
int main()
{
	read(tt);
	while(tt--)
	{
		read(n,m);
		F(i,0,n)read(a[i]);
		F(i,0,n)read(b[i]);
		F(i,0,n)s[i+1]=s[i]+a[i]-b[i];
		F(i,0,m)adj[--read(l[i])].emplace_back(i),adj[read(r[i])].emplace_back(i);
		p.clear();
		F(i,0,n+1)if(s[i])p.emplace(i);
		qf=qr=0;
		F(i,0,m)if(s[l[i]]==0&&s[r[i]]==0)q[qr++]=i;
		while(qf<qr)
		{
			int u=q[qf++],x=l[u],y=r[u];
			auto be=p.lower_bound(x),en=p.lower_bound(y);
			for(auto it=be;it!=en;++it)
			{
				int i=*it;
				s[i]=0;
				for(int j:adj[i])if(!s[l[j]^r[j]^i])q[qr++]=j;
			}
			p.erase(be,en);
		}
		puts(p.empty()?"YES":"NO");
		F(i,0,n+1)adj[i].clear();
	}
	return 0;
}