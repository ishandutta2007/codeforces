#include<bits/stdc++.h>
#define ll long long
#define inf 1000000000
#define N 300009
using namespace std;

int n,m,cnt1,cnt2,ans,lim,a[N],b[N];
void check(int x,int y,int u,int v,int pos,int lim){
	ans=min(ans,abs(y-pos)+abs(v-pos)+(x!=u?(abs(x-u)-1)/lim+1:0));
}
void solve(int x,int y,int u,int v,int *a,int cnt,int lim){
	if (!cnt) return;
	int l=1,r=cnt,mid;
	while (l<r){
		mid=l+r>>1;
		if (a[mid]<y) l=mid+1; else r=mid;
	}
	check(x,y,u,v,a[l],lim);
	if (l>1) check(x,y,u,v,a[l-1],lim);
	l=1; r=cnt;
	while (l<r){
		mid=l+r>>1;
		if (a[mid]<v) l=mid+1; else r=mid;
	}
	check(x,y,u,v,a[l],lim);
	if (l>1) check(x,y,u,v,a[l-1],lim);
}
int main(){
	scanf("%d%d%d%d%d",&n,&m,&cnt1,&cnt2,&lim);
	int i,x,y,u,v;
	for (i=1; i<=cnt1; i++) scanf("%d",&a[i]);
	for (i=1; i<=cnt2; i++) scanf("%d",&b[i]);
	sort(a+1,a+cnt1+1);
	sort(b+1,b+cnt2+1);
	int cas;
	scanf("%d",&cas);
	while (cas--){
		scanf("%d%d%d%d",&x,&y,&u,&v);
		ans=inf;
		solve(x,y,u,v,a,cnt1,1);
		solve(x,y,u,v,b,cnt2,lim);
		if (x==u) ans=min(ans,abs(y-v));
		printf("%d\n",ans);
	}
	return 0;
}