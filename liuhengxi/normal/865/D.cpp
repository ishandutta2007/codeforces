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
int n;
long long ans;
priority_queue<int,vector<int>,greater<int> > q;
int main()
{
	read(n);
	F(i,0,n)
	{
		int a;read(a);
		if(!q.empty()&&q.top()<a)ans+=a-q.top(),q.pop(),q.push(a);
		q.push(a);
	}
	printf("%lld\n",ans);
	return 0;
}