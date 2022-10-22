#include<cstdio>
#include<queue>
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
int n,k,a[N],b[N];
long long ans;
long long calc(int x,int y)
{
	long long a=x%y,b=y-a;
	return a*(x/y+1)*(x/y+1)+b*(x/y)*(x/y);
}
struct cmp
{
	bool operator()(int x,int y)const
	{
return calc(a[x],b[x]+1)-calc(a[x],b[x])>calc(a[y],b[y]+1)-calc(a[y],b[y]);
	}
};
priority_queue<int,vector<int>,cmp> q;
int main()
{
	read(n);read(k);
	F(i,0,n)read(a[i]);
	F(i,0,n)b[i]=1;
	F(i,0,n)ans+=(long long)a[i]*a[i];
	F(i,0,n)q.push(i);
	for(;k>n;--k)
	{
		int x=q.top();q.pop();
		ans+=calc(a[x],b[x]+1)-calc(a[x],b[x]);
		++b[x];
		q.push(x);
	}
	printf("%lld\n",ans);
	return 0;
}