#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5,P=998244353;
int T,n,hd[N],to[N<<1],nxt[N<<1],tot,tx[N<<1],ty[N<<1],pr[N/3],cnt,mx[N/3],w[N/3],qwq[N];bool isnpr[N];vector<int> vp[N];
int qpow(int x,int y){
	int res=1;
	for(;y;x=1ll*x*x%P,y>>=1)
		if(y&1)res=1ll*res*x%P;
	return res;
}
void add(int x,int y,int xx,int yy){to[++tot]=y,nxt[tot]=hd[x],hd[x]=tot,tx[tot]=xx,ty[tot]=yy;}
void dfs(int x,int Fa){
	for(int i=hd[x],y;i;i=nxt[i])if((y=to[i])!=Fa){
		for(int j:vp[ty[i]])w[j]++;
		for(int j:vp[tx[i]])w[j]--,mx[j]=max(mx[j],-w[j]);
		qwq[y]=1ll*qwq[x]*ty[i]%P*qpow(tx[i],P-2)%P,dfs(y,x);
		for(int j:vp[tx[i]])w[j]++;
		for(int j:vp[ty[i]])w[j]--;
	}
}
void solve(){
	scanf("%d",&n),fill(hd,hd+n+1,0),fill(mx,mx+min(n,cnt+1),0),tot=0,qwq[1]=1;
	for(int i=1,u,v,x,y;i<n;i++)scanf("%d%d%d%d",&u,&v,&x,&y),add(u,v,x,y),add(v,u,y,x);
	dfs(1,0);
	int ans=0;
	for(int i=1;i<=n;i++)ans=(ans+qwq[i])%P;
	for(int i=1;i<=cnt&&pr[i]<=n;i++)ans=1ll*ans*qpow(pr[i],mx[i])%P;
	printf("%d\n",ans);
}
int main(){
	for(int i=2;i<N;i++){
		if(!isnpr[i])pr[++cnt]=i;
		for(int j=1;j<=cnt&&i*pr[j]<N;j++){
			isnpr[i*pr[j]]=1;
			if(i%pr[j]==0)break;
		}
	}
	for(int i=1;i<=cnt;i++)
		for(int j=pr[i];j<N;j+=pr[i]){
			int t=j;
			while(t%pr[i]==0)t/=pr[i],vp[j].push_back(i);
		}
	scanf("%d",&T);
	while(T--)solve();
	return 0;
}