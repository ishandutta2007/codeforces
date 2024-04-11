#include<cstdio>
#include<algorithm>
#include<queue>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=2e5+5;
const long long LLINF=0x3fffffffffffffffll;
template<typename T>void readmain(T &x)
{
	bool neg=false;
	int c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
template<typename T>T& read(T &x){readmain(x);return x;}
template<typename T,typename ...Tr>void read(T &x,Tr&... r){readmain(x);read(r...);}
int n,m,k,aa,c[N],l[N],a[4][N],nn[4],lo;
long long s[4][N],ans=LLINF;
struct data_structure
{
	priority_queue<int> q;
	priority_queue<int,vector<int>,greater<int> > qq;
	long long now;
	void push(int x)
	{
		if(qq.empty()||x<=qq.top())q.push(x),now+=x;
		else qq.push(x);
	}
	bool adjust(int b)
	{
		while((int)(q.size())<b&&!qq.empty())q.push(qq.top()),now+=qq.top(),qq.pop();
		while((int)(q.size())>b)qq.push(q.top()),now-=q.top(),q.pop();
		return (int)(q.size())==b;
	}
}ds;
int main()
{
	read(n,m,k);
	F(i,0,n)read(c[i]);
	F(i,0,read(aa)){int p;l[--read(p)]|=2;}
	F(i,0,read(aa)){int p;l[--read(p)]|=1;}
	F(i,0,n)a[l[i]][nn[l[i]]++]=c[i];
	sort(a[0],a[0]+nn[0]);
	sort(a[1],a[1]+nn[1]);
	sort(a[2],a[2]+nn[2]);
	sort(a[3],a[3]+nn[3]);
	F(i,0,nn[0])s[0][i+1]=s[0][i]+a[0][i];
	F(i,0,nn[1])s[1][i+1]=s[1][i]+a[1][i];
	F(i,0,nn[2])s[2][i+1]=s[2][i]+a[2][i];
	F(i,0,nn[3])s[3][i+1]=s[3][i]+a[3][i];
	lo=max({k-nn[1],k-nn[2],0});
	if(lo>nn[3])return puts("-1"),0;
	F(i,0,nn[0])ds.push(a[0][i]);
	F(i,k-lo,nn[1])ds.push(a[1][i]);
	F(i,k-lo,nn[2])ds.push(a[2][i]);
	F(x,lo,nn[3]+1)
	{
		int other=x+max(k-x,0)*2;
		if(m-other>=0&&ds.adjust(m-other))
		{
			long long tmp=ds.now+s[1][max(k-x,0)]+s[2][max(k-x,0)]+s[3][x];
			ans=min(ans,tmp);
		}
		if(k-x-1>=0)ds.push(a[1][k-x-1]);
		if(k-x-1>=0)ds.push(a[2][k-x-1]);
	}
	if(ans==LLINF)ans=-1;
	printf("%lld\n",ans);
	return 0;
}