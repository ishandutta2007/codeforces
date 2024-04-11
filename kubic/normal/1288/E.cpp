#include <bits/stdc++.h>
using namespace std;
#define N 300005
int n,m,pr[N],mn[N],mx[N],v[N<<1];
int max(int x,int y) {return x>y?x:y;}
void upd(int x,int _v) {for(;x<=n+m;x+=x&-x) v[x]+=_v;}
int qSm(int x) {int res=0;for(;x;x-=x&-x) res+=v[x];return res;}
int main()
{
	srand(time(0));scanf("%d %d",&n,&m);
	for(int i=1;i<=n;++i) pr[i]=n-i+1,mn[i]=mx[i]=i,upd(pr[i],1);
	for(int i=1,x;i<=m;++i)
	{
		scanf("%d",&x);mn[x]=1;mx[x]=max(mx[x],n-qSm(pr[x])+1);
		upd(pr[x],-1);upd(pr[x]=n+i,1);
	}
	for(int i=1;i<=n;++i)
		printf("%d %d\n",mn[i],max(mx[i],n-qSm(pr[i])+1));
	return 0;
}