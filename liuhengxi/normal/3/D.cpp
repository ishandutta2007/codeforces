#include<cstdio>
#include<queue>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
#define fail return puts("-1"),0;
using namespace std;
const int N=5e4+5,M=1e7;
const long long INF=1e12;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n;long long a[N],b[N],c[N],ans;
char s[N];
struct node
{
	int id;
	node(int a){id=a;}
	bool operator<(node b)const{return c[b.id]>c[id];}
};
priority_queue<node>q;
int main()
{
	scanf("%s",s);
	while(s[n])++n;
	if(n&1)fail;
	F(i,0,n)if(s[i]=='?')read(a[i]),read(b[i]);
	else
	{
		if(s[i]=='(')a[i]=0,b[i]=INF;
		else a[i]=INF,b[i]=0;
	}
	F(i,0,n)s[i]='(';
	F(i,0,n)c[i]=b[i]-a[i]-M,ans+=a[i];
	ans+=M*(long long)(n>>1);
	F(i,0,n)
	{
		if(!q.empty()&&node(i)<q.top())
		{
			s[q.top().id]='(',s[i]=')',ans+=c[i]-c[q.top().id];
			if(q.top().id!=n+1)q.pop(),q.push(n+1);else q.pop();
			q.push(i);
		}
		else q.push(n+1);
	}
	if(q.size()!=(unsigned)(n>>1)||ans>=INF)fail;
	printf("%lld\n",ans);
	puts(s);
	return 0;
}