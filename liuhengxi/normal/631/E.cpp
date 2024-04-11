#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=2e5+5;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
struct query
{
	int i,k;
	bool operator<(query b)const{return k<b.k;}
}q[N];
int n,a[N],sta[N],top;
long long s[N],ans;
bool cmp(int u,int v,int w){return (s[v]-s[u])*(w-v)>=(s[w]-s[v])*(v-u);}
int main()
{
	read(n);
	F(i,0,n)read(a[i]),q[q[i].i=i].k=a[i];
	F(i,0,n)s[i+1]=s[i]+a[i];
	sta[top++]=0;sta[top++]=1;
	F(i,2,n+1)
	{
		while(top>1&&cmp(sta[top-2],sta[top-1],i))--top;
		sta[top++]=i;
	}
	sort(q,q+n);
	for(int i=0,j=0;i<n;++i)
	{
		long long k=q[i].k;
		while(j<top-1&&s[sta[j]]-sta[j]*k>s[sta[j+1]]-sta[j+1]*k)++j;
		ans=max(ans,(s[q[i].i]-q[i].i*k)-(s[sta[j]]-sta[j]*k));
	}
	F(i,0,n)ans+=(i+1ll)*a[i];
	printf("%lld\n",ans);
	return 0;
}