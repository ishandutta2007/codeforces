#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
int n,m,hd[N],nxt[N<<1],to[N<<1],tot,a[N],f[N],deg[N];ll k;queue<int> q;bool vst[N];
void add(int x,int y){to[++tot]=y,nxt[tot]=hd[x],hd[x]=tot;}
bool check(int w){
	fill(deg,deg+n+1,0),fill(f,f+n+1,0),fill(vst,vst+n+1,0);
	for(int i=1;i<=n;i++)if(a[i]<=w)
		for(int j=hd[i];j;j=nxt[j])if(a[to[j]]<=w)deg[to[j]]++;
	for(int i=1;i<=n;i++)if(a[i]<=w&&!deg[i])q.push(i);
	while(!q.empty()){
		int x=q.front();q.pop();vst[x]=1;
		f[x]++;
		for(int i=hd[x],y;i;i=nxt[i])if(a[y=to[i]]<=w){
			f[y]=max(f[y],f[x]);
			if((--deg[y])==0)q.push(y);
		}
	}
	for(int i=1;i<=n;i++)if(a[i]<=w&&!vst[i])return 1;
	for(int i=1;i<=n;i++)if(a[i]<=w&&f[i]>=k)return 1;
	return 0;
}
int main(){
	scanf("%d%d%lld",&n,&m,&k);if(k>n)k=n+1;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1,x,y;i<=m;i++)scanf("%d %d",&x,&y),add(x,y);
	int l=1,r=1e9+2;
	while(l<=r){
		int mid=l+r>>1;
		if(check(mid))r=mid-1;
		else l=mid+1;
	}
	if(r>1e9){printf("-1\n");return 0;}
	else printf("%d\n",l);
	return 0;
}