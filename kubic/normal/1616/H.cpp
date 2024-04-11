#include <bits/stdc++.h>
using namespace std;
#define N 150005
#define M 5000005
#define MOD 998244353
int n,m,cntP=1,a[N],w[N];struct Point {int vl,ch[2];}pt[M];
int add(int x,int y) {x+=y;return x<MOD?x:x-MOD;}
void ins(int vl)
{
	int p=1;++pt[p].vl;
	for(int i=29,t;i>=0;--i) {t=vl>>i&1;if(!pt[p].ch[t]) pt[p].ch[t]=++cntP;p=pt[p].ch[t];++pt[p].vl;}
}
int dfs(int p1,int p2,int d)
{
	if(!p1 && !p2) return 0;if(d<0) return p1==p2?w[pt[p1].vl]:1ll*w[pt[p1].vl]*w[pt[p2].vl]%MOD;
	if(m>>d&1)
	{
		if(p1==p2) return add(dfs(pt[p1].ch[0],pt[p2].ch[1],d-1),add(w[pt[pt[p1].ch[0]].vl],w[pt[pt[p2].ch[1]].vl]));
		int t1=dfs(pt[p1].ch[0],pt[p2].ch[1],d-1),t2=dfs(pt[p1].ch[1],pt[p2].ch[0],d-1),res=1ll*t1*t2%MOD;
		res=add(res,1ll*t1*add(w[pt[pt[p1].ch[1]].vl],w[pt[pt[p2].ch[0]].vl])%MOD);
		res=add(res,1ll*t2*add(w[pt[pt[p1].ch[0]].vl],w[pt[pt[p2].ch[1]].vl])%MOD);
		res=add(res,1ll*w[pt[pt[p1].ch[0]].vl]*w[pt[pt[p2].ch[0]].vl]%MOD);
		res=add(res,1ll*w[pt[pt[p1].ch[1]].vl]*w[pt[pt[p2].ch[1]].vl]%MOD);return add(res,add(t1,t2));
	}return add(dfs(pt[p1].ch[0],pt[p2].ch[0],d-1),dfs(pt[p1].ch[1],pt[p2].ch[1],d-1));
}
int main()
{
	scanf("%d %d",&n,&m);for(int i=1,vl;i<=n;++i) w[i]=add(w[i-1],w[i-1]+1),scanf("%d",&vl),ins(vl);
	printf("%d\n",dfs(1,1,29));return 0;
}