#include<set>
#include<map>
#include<deque>
#include<queue>
#include<stack>
#include<cmath>
#include<ctime>
#include<bitset>
#include<string>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<complex>
#include<iostream>
#include<algorithm>
#define ll long long
#define inf 1e9
using namespace std;

const int maxn = 210000;

int n;
int V[maxn],T[maxn];

struct node
{
	ll c;
	friend inline bool operator <(const node x,const node y){return x.c>y.c;}
};
priority_queue<node>q;
int qn;
ll flagq;

int main()
{
	//freopen("tmp.in","r",stdin);
	//freopen("tmp.out","w",stdout);
	
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&V[i]);
	for(int i=1;i<=n;i++) scanf("%d",&T[i]);
	
	qn=0; flagq=0;
	for(int i=1;i<=n;i++)
	{
		ll ans=0;
		while(qn)
		{
			const node now=q.top();
			if(now.c-flagq<=T[i]) qn--,ans+=now.c-flagq,q.pop();
			else break;
		}
		ans+=(ll)qn*T[i];
		ans+=min(V[i],T[i]);
		if(V[i]>T[i]) q.push((node){flagq+V[i]}),qn++;
		flagq+=T[i];
		printf("%lld",ans);
		if(i!=n) putchar(' ');
	}
	
	return 0;
}