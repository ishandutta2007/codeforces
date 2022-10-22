#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e5+5;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,a[N],c[N],id[N],mx;
long long ans;
bool cmp(int u,int v){return a[u]<a[v];}
int main()
{
	read(n);
	F(i,0,n)read(a[i]),read(c[i]),ans+=c[i],id[i]=i;
	sort(id,id+n,cmp);
	mx=a[id[0]]+c[id[0]];
	F(i,1,n)
	{
		if(a[id[i]]-mx>0)ans+=a[id[i]]-mx;
		if(a[id[i]]+c[id[i]]>mx)mx=a[id[i]]+c[id[i]];
	}
	printf("%lld\n",ans);
	return 0;
}