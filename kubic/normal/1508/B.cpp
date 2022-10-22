#include <bits/stdc++.h>
using namespace std;
#define N 100005
#define ll long long
const ll lim=1e18;
int T,n,nw,len,ans[N];ll m;
void slv()
{
	scanf("%d %lld",&n,&m);nw=len=0;
	if(n<63 && m>1ll<<n-1) {puts("-1");return;}
	while(len<n)
	{
		if(n-len>62) ans[++len]=nw+1,nw=len;
		else
		{
			int ps=0;ll t=0,lst=0;
			for(int i=len+1;i<=n;++i)
			{
				lst=t;if(i<n) t+=1ll<<n-i-1;else ++t;
				ps=i;if(t>=m) break;
			}for(int i=ps;i>nw;--i) ans[++len]=i;
			nw=len;m-=lst;
		}
	}for(int i=1;i<=n;++i) printf("%d ",ans[i]);
	puts("");
}
int main()
{
	scanf("%d",&T);while(T--) slv();
	return 0;
}