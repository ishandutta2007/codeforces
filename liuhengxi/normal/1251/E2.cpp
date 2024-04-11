#include<cstdio>
#include<queue>
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
struct person
{
	int m,p;
	bool operator<(person b)const{return m!=b.m?m>b.m:p<b.p;}
}p[N];
int t,n;
priority_queue<int,vector<int>,greater<int> >q;
int main()
{
	read(t);
	while(t--)
	{
		int bought=0;long long ans=0;
		read(n);
		F(i,0,n)read(p[i].m),read(p[i].p);
		sort(p,p+n);
		while(!q.empty())q.pop();
		F(i,0,n)
		{
			q.push(p[i].p);
			while(bought+n-i-1<p[i].m)ans+=q.top(),q.pop(),++bought;
		}
		printf("%lld\n",ans);
	}
	return 0;
}