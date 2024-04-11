#include <bits/stdc++.h>
using namespace std;
#define N 400005
#define M 20000005
int SZ=2e7,n,ans,a[N],v[M];
void upd(int x,int _v) {for(;x<=SZ;x+=x&-x) v[x]+=_v;}
int qSm(int x)
{
	int res=0;if(x<=0) return 0;if(x>SZ) x=SZ;
	for(;x;x-=x&-x) res+=v[x];return res;
}
int main()
{
	scanf("%d",&n);for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	for(int i=0,all,cnt;(1<<i)<=SZ;++i)
	{
		all=(1<<i+1)-1;cnt=0;
		for(int j=1,t;j<=n;++j)
		{
			t=a[j]&all;cnt+=qSm((1<<i+1)-t)-qSm((1<<i)-t);cnt&=1;
			cnt+=qSm((1<<i+2)-t)-qSm((1<<i)+(1<<i+1)-t);cnt&=1;upd(t+1,1);
		}for(int j=1;j<=n;++j) upd((a[j]&all)+1,-1);if(cnt) ans|=1<<i;
	}printf("%d\n",ans);return 0;
}