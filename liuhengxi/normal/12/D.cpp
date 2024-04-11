#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=5e5+5;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
struct fsb
{
	int x,y,z;
	bool operator<(fsb b)const{return x!=b.x?x>b.x:(y!=b.y?y<b.y:z<b.z);}
}a[N];
int n,v[N],ans,c[N];
void add(int x,int y){for(++x;x<=n;x+=(x&-x))c[x]=max(c[x],y);}
int sum(int x){int ans=0;for(;x;x-=(x&-x))ans=max(ans,c[x]);return ans;}
int main()
{
	read(n);
	F(i,0,n)read(a[i].x);
	F(i,0,n)read(a[i].y),v[i]=a[i].y;
	F(i,0,n)read(a[i].z);
	sort(v,v+n);sort(a,a+n);
	F(i,0,n)a[i].y=n-1-(lower_bound(v,v+n,a[i].y)-v);
	F(i,0,n)
	{
		if(sum(a[i].y)>a[i].z)++ans;
		add(a[i].y,a[i].z);
	}
	printf("%d\n",ans);
	return 0;
}