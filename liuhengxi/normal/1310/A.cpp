#include<cstdio>
#include<algorithm>
#include<queue>
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
int n,a[N],t[N],id[N];
long long sum,ans;
bool cmp(int x,int y){return a[x]<a[y];}
priority_queue<int> q;
int main()
{
	read(n);
	F(i,0,n)read(a[id[i]=i]);
	F(i,0,n)read(t[i]);
	sort(id,id+n,cmp);
	q.push(t[id[0]]);
	sum+=t[id[0]];
	F(i,1,n)
	{
		F(j,0,a[id[i]]-a[id[i-1]])if(!q.empty())
		{
			sum-=q.top();q.pop();
			ans+=sum;
		}
		sum+=t[id[i]];q.push(t[id[i]]);
	}
	while(!q.empty())
	{
		sum-=q.top();q.pop();
		ans+=sum;
	}
	printf("%lld\n",ans);
	return 0;
}