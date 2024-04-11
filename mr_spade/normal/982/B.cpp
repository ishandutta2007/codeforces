#include<cstdio>
#include<queue>
using std::vector;
using std::priority_queue;
const int N=2e5+5;
int n;
char s[N<<1];
int w[N];
struct cmp0
{
	inline bool operator()(int a,int b)
	{
		return w[a]>w[b];
	}
};
struct cmp1
{
	inline bool operator()(int a,int b)
	{
		return w[a]<w[b];
	}
};
priority_queue<int,vector<int>,cmp0> Q0;
priority_queue<int,vector<int>,cmp1> Q1;
signed main()
{
	register int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&w[i]);
	scanf("%s",s+1);
	for(i=1;i<=n;i++)
		Q0.push(i);
	for(i=1;i<=n<<1;i++)
		if(s[i]=='0')
		{
			printf("%d ",Q0.top());
			Q1.push(Q0.top());Q0.pop();
		}
		else
		{
			printf("%d ",Q1.top());
			Q1.pop();
		}
	putchar('\n');
	return 0;
}