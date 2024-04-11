#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
#define fail {puts("NO");goto end;}
using namespace std;
const int N=3e5+5;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int t,n,a[N],b[N],ida[N],idb[N],d[N],c[N];
bool cmpa(int u,int v){return a[u]!=a[v]?a[u]<a[v]:u<v;}
bool cmpb(int u,int v){return b[u]!=b[v]?b[u]<b[v]:u<v;}
void add(int x,int y){for(++x;x<=n;x+=(x&-x))c[x]=c[x]>y?c[x]:y;}
int sum(int x)
{
	int ans=0;
	for(;x;x-=(x&-x))ans=ans>c[x]?ans:c[x];
	return ans;
}
int main()
{
	read(t);
	while(t--)
	{
		read(n);
		F(i,0,n)d[i]=0;
		F(i,0,n)read(a[i]),++d[--a[i]];
		F(i,0,n)read(b[i]),--d[--b[i]];
		F(i,0,n)if(d[i])fail;
		F(i,0,n)ida[i]=i;
		F(i,0,n)idb[i]=i;
		sort(ida,ida+n,cmpa);
		sort(idb,idb+n,cmpb);
		F(i,0,n)a[ida[i]]=i;
		F(i,0,n)b[idb[i]]=i;
		F(i,0,n)c[i+1]=0;
		F(i,0,n)
		{
			if(sum(a[i])>idb[a[i]])fail;
			add(a[i],idb[a[i]]);
		}
		puts("YES");
		end:;
	}
	return 0;
}