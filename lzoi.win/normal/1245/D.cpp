#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=2005;
int n,x[MAXN],y[MAXN],c[MAXN],k[MAXN];
struct node{
	int u,v;
	ll w;
}ed[MAXN*MAXN];
bool operator <(node a,node b){
	return a.w<b.w;
}
int cnte;
int pre[MAXN];
int fnd(int x){
	if(x!=pre[x]) pre[x]=fnd(pre[x]);
	return pre[x];
}
int cntw,wel[MAXN],cntc,con[MAXN];
ll ans;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",x+i,y+i);
	for(int i=1;i<=n;i++)
		scanf("%d",c+i);
	for(int i=1;i<=n;i++){
		scanf("%d",k+i);
		ed[++cnte]=(node){i,n+1,c[i]};
		for(int j=1;j<i;j++){
			ll w=abs(x[i]-x[j])+abs(y[i]-y[j]);
			w*=(k[i]+k[j]);
			ed[++cnte]=(node){i,j,w};
		}
		pre[i]=i;
	}
	sort(ed+1,ed+cnte+1);
	for(int i=1;i<=cnte;i++){
		const int s1=fnd(ed[i].u),s2=fnd(ed[i].v);
		if(s1==s2) continue;
		pre[s1]=s2;
		ans+=ed[i].w;
		if(ed[i].v==n+1) wel[++cntw]=ed[i].u;
		else con[++cntc]=i;
	}
	printf("%I64d\n",ans);
	printf("%d\n",cntw);
	for(int i=1;i<=cntw;i++)
		printf("%d ",wel[i]);
	puts("");
	printf("%d\n",cntc);
	for(int i=1;i<=cntc;i++)
		printf("%d %d\n",ed[con[i]].u,ed[con[i]].v);
	return 0;
}