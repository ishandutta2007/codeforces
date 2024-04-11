#include<bits/stdc++.h>
#define ll long long
#define inf 1000000000
#define vi vector<int>
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll,ll>
#define mpr make_pair
#define fi first
#define se second
#define pq priority_queue<int>
#define pqll priority_queue<ll>
#define up(x,y) (x<(y)?x=(y):0)
#define dn(x,y) (x>(y)?x=(y):0)
#define ad(x,y) (x=(x+(y))%mod)
#define N 1000009
using namespace std;

int n,m,q[N],vis[N]; bool bo[N]; set<int> S[N],T[N];
int read(){
	int x=0; char ch=getchar(); bool flag=0;
	while (ch<'0' || ch>'9'){ if (ch=='-') flag=1; ch=getchar(); }
	while (ch>='0' && ch<='9'){ x=x*10+ch-'0'; ch=getchar(); }
	return flag?-x:x;
}
void solve(int cnt,int *q){
	if (!cnt) return;
	int i,x;
	for (i=1; i<=cnt; i++) vis[q[i]]=0; 
	for (i=1; i<=cnt; i++){
		x=q[i]; if (vis[x]) continue;
		bo[x]=1; vis[x]=2;
		for (int p:S[x]){ vis[p]=2; T[p].erase(x); }
		for (int p:T[x]){ if (!vis[p]) vis[p]=1; S[p].erase(x); }
	}
	int pt=0,nq[cnt];
	for (i=1; i<=cnt; i++){
		x=q[i]; if (vis[x]==1) nq[++pt]=x;
	}
	solve(pt,nq);
	for (i=1; i<=cnt; i++){
		x=q[i];
		if (bo[x]){
			for (int p:S[x]) if (bo[p]){ bo[x]=0; break; }
			for (int p:T[x]) if (bo[p]){ bo[x]=0; break; }
		}
	}
}
int main(){
	n=read(); m=read();
	int i,x,y;
	for (i=1; i<=m; i++){
		x=read(); y=read();
		S[x].insert(y); T[y].insert(x);
	}
	for (i=1; i<=n; i++) q[i]=i;
	solve(n,q);
	int cnt=0;
	for (i=1; i<=n; i++) if (bo[i]) cnt++;
	printf("%d\n",cnt);
	for (i=1; i<=n; i++) if (bo[i]) printf("%d ",i); puts("");
	return 0;
}