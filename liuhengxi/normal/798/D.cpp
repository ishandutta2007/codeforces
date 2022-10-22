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
int n,a[N],b[N],id[N],ans[N],cnt;
int main()
{
	read(n);F(i,0,n)read(a[i]);F(i,0,n)read(b[i]);F(i,0,n)id[i]=i;
	sort(id,id+n,[](int u,int v){return a[u]>a[v];});
	ans[cnt++]=id[0];if(~n&1)ans[cnt++]=id[1];
	for(int i=(~n&1)+1;i<n;i+=2)ans[cnt++]=b[id[i]]>b[id[i+1]]?id[i]:id[i+1];
	printf("%d\n",cnt);
	F(i,0,cnt)printf("%d ",ans[i]+1);
	puts("");
	return 0;
}