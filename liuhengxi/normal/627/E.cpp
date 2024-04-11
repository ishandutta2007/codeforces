#include<cstdio>
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
constexpr int N=3005;
namespace list
{
	int val[N],prev[N],next[N];
	void remove(int x)
	{
		if(~prev[x])next[prev[x]]=next[x];
		if(~next[x])prev[next[x]]=prev[x];
	}
}
int r,c,n,k,x[N],y[N],id[N],t[N],pos[N],lv[N],rv[N];
long long ans=0;
int main()
{
	read(r,c,n,k);
	F(i,0,n)read(x[i],y[i]),--x[i],--y[i],id[i]=i;
	sort(id,id+n,[](int u,int v){return x[u]>x[v];});
	F(i,0,n)t[i]=x[i];
	F(i,0,n)x[i]=t[id[i]];
	F(i,0,n)t[i]=y[i];
	F(i,0,n)y[i]=t[id[i]];
	F(i,0,r)
	{
		int cnt=0;
		for(int j=0;j<n&&x[j]>=i;++j)id[cnt++]=j;
		sort(id,id+cnt,[](int u,int v){return y[u]<y[v];});
		F(j,0,cnt)pos[id[j]]=j,list::val[j]=y[id[j]],list::prev[j]=j-1,list::next[j]=j!=cnt-1?j+1:-1;
		int cur=0;
		for(int j=0,p=0;j<c;++j)
		{
			while(p<cnt&&list::val[p]<j)++p;
			if(p+k<=cnt)cur+=c-list::val[p+k-1];
		}
		for(int j=r,p=0;--j>=i;)
		{
			ans+=cur;
			for(;p<n&&x[p]==j;++p)
			{
				int lc=0,rc=0;
				lv[0]=rv[0]=list::val[pos[p]];
				for(int u=list::prev[pos[p]];lc<k&&~u;u=list::prev[u])lv[++lc]=list::val[u];
				while(lc<k)lv[++lc]=-1;
				for(int u=list::next[pos[p]];rc<k&&~u;u=list::next[u])rv[++rc]=list::val[u];
				while(rc<k)rv[++rc]=c;
				F(le,0,k)cur-=(lv[le]-lv[le+1])*(rv[k-le]-rv[k-1-le]);
				list::remove(pos[p]);
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}