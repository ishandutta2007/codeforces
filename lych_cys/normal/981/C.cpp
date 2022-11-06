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
#define up(x,y) (x<(y)?x=(y):0)
#define dn(x,y) (x>(y)?x=(y):0)
#define ad(x,y) (x=(x+(y))%mod)
#define N 100009
using namespace std;

int n,cnt,tot,fst[N],pnt[N<<1],nxt[N<<1],dgr[N],a[N],b[N]; bool vis[N];
int read(){
	int x=0; char ch=getchar(); bool flag=0;
	while (ch<'0' || ch>'9'){ if (ch=='-') flag=1; ch=getchar(); }
	while (ch>='0' && ch<='9'){ x=x*10+ch-'0'; ch=getchar(); }
	return flag?-x:x;
}
void gg(){ puts("No"); exit(0); }
void add(int x,int y){
	dgr[x]++;
	pnt[++tot]=y; nxt[tot]=fst[x]; fst[x]=tot;
}
void dfs(int x){
	int i,y,tmp=0; vis[x]=1;
	for (i=fst[x]; i; i=nxt[i]){
		y=pnt[i];
		if (!vis[y]){
			tmp++; dfs(y);
		}
	}
	if (tmp>1) gg();
	if (!tmp) b[cnt]=x;
}
int main(){
	n=read();
	int i,k,x,y;
	for (i=1; i<n; i++){
		x=read(); y=read();
		add(x,y); add(y,x);	
	}
	for (i=k=1; i<=n; i++) if (dgr[i]>dgr[k]) k=i;
	vis[k]=1;
	for (i=fst[k]; i; i=nxt[i]){
		cnt++; dfs(pnt[i]);
	}
	puts("Yes");
	printf("%d\n",cnt);
	for (i=1; i<=cnt; i++) printf("%d %d\n",k,b[i]);
	return 0;
}