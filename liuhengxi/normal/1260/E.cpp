#include<cstdio>
#include<queue>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=(1<<18)+5;
template<typename T>void readmain(T &x)
{
	bool neg=false;
	int c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
template<typename T>T& read(T &x){readmain(x);return x;}
template<typename T,typename ...Tr>void read(T &x,Tr&... r){readmain(x);read(r...);}
int n,a[N];
long long ans;
priority_queue<int,vector<int>,greater<int> > q;
int main()
{
	read(n);
	F(i,0,n)read(a[i]);
	for(int i=n;~--i;)
	{
		if(!~a[i])break;
		q.push(a[i]);
		if(!((i+1)&i))ans+=q.top(),q.pop();
	}
	printf("%lld\n",ans);
	return 0;
}