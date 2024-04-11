#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=3e5+5,INF=0x3fffffff;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
struct ss
{
	int v,p;
	bool operator<(ss b)const
	{
		return v!=b.v?v<b.v:p<b.p;
	}
}s[N];
int t,n,a[N],ans[N];
int main()
{
	read(t);
	while(t--)
	{
		read(n);
		F(i,0,n)read(a[i]);
		F(i,0,n)s[s[i].p=i].v=a[i];
		sort(s,s+n);
		F(i,0,n)ans[i]=INF;
		for(int i=0,j=0;i<n;i=j)
		{
			int mxd=0;
			while(j<n&&s[i].v==s[j].v)++j;
			mxd=max(s[i].p+1,n-s[j-1].p);
			F(k,i+1,j)mxd=max(mxd,s[k].p-s[k-1].p);
			--mxd;
			ans[mxd]=min(ans[mxd],s[i].v);
		}
		F(i,1,n)ans[i]=min(ans[i],ans[i-1]);
		F(i,0,n)if(ans[i]==INF)ans[i]=-1;
		F(i,0,n)printf("%d ",ans[i]);
		printf("\n");
	}
	return 0;
}