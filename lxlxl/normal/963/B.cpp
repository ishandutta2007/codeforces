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
using namespace std;

const int maxn = 410000;

int n;
int d[maxn];
struct edge{int y,nex;}a[maxn<<1]; int len,fir[maxn];
inline void ins(const int x,const int y){a[++len]=(edge){y,fir[x]};fir[x]=len;}
int t[maxn],tp;
int ans[maxn],ansn;
void dfs(const int x,int fa)
{
	for(int k=fir[x],y=a[k].y;k;k=a[k].nex,y=a[k].y) if(y!=fa)
		dfs(y,x);
	if(!d[x])
	{
		for(int k=fir[x],y=a[k].y;k;k=a[k].nex,y=a[k].y) d[y]^=1;
		ans[++ansn]=x;
	}
	else t[++tp]=x;
}

int main()
{
	//freopen("tmp.in","r",stdin);
	//freopen("tmp.out","w",stdout);
	
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int x; scanf("%d",&x);
		if(x) ins(x,i),ins(i,x),d[x]^=1,d[i]^=1;
	}
	dfs(1,0);
	while(tp)
	{
		int x=t[tp--];
		if(d[x]) return puts("NO"),0;
		ans[++ansn]=x;
		for(int k=fir[x],y=a[k].y;k;k=a[k].nex,y=a[k].y) d[y]^=1;
	}
	puts("YES");
	for(int i=1;i<=ansn;i++) printf("%d\n",ans[i]);
	
    return 0;
}