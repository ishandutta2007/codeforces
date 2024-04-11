#include<cstdio>
#include<queue>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n;long long ans;
priority_queue<long long,vector<long long>,greater<long long> > q;
int main()
{
	read(n);
	F(i,0,n){int a;read(a);q.push(a);}
	if((~q.size())&1)
	{
		long long a=q.top();q.pop();
		long long b=q.top();q.pop();
		ans+=a+b;
		q.push(a+b);
	}
	while(q.size()>1)
	{
		long long a=q.top();q.pop();
		long long b=q.top();q.pop();
		long long c=q.top();q.pop();
		ans+=a+b+c;
		q.push(a+b+c);
	}
	printf("%lld\n",ans);
	return 0;
}