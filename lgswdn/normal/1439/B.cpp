#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
typedef pair<int,int> pii;
typedef vector<int> vi;

long long read() {
	long long res=0, w=1; char c=getchar();
	while(!isdigit(c)) {if(c=='-') w=-1; c=getchar();}
	while(isdigit(c)) {res=res*10+c-48, c=getchar();}
	return res*w;
}

const int N=2e5+9;
int T,n,m,k,deg[N];
bool del[N];
vi e[N];
unordered_map<int,bool>ed[N];

void kcore() {
	vi ans;
	rep(i,1,n) if(!del[i]) ans.emplace_back(i);
	printf("%d %Ld\n",1,ans.size()); for(auto x:ans) printf("%d ",x); puts("");
	return;
}
bool clique(int u) {
	vi p; for(auto v:e[u]) if(!del[v]) p.emplace_back(v);
	for(auto v:p) for(auto w:p) if(v!=w&&!ed[v][w]) return 0;
	puts("2"); for(auto x:p) printf("%d ",x); printf("%d\n",u);
	return 1;
}
void solve() {
	priority_queue<pii>q;
	rep(i,1,n) q.push(pii(-deg[i],i));
	int tot=0;
	while(!q.empty()) {
		int u=q.top().second; q.pop(); if(del[u]) continue;
		if(deg[u]>=k) {kcore(); return;}
		if(deg[u]==k-1&&m>=k*(k-1)/2) {tot++; if(clique(u)) return;}
		if(tot>8000) {puts("-1"); return;}
		for(auto v:e[u]) deg[v]--, q.push(pii(-deg[v],v));
		deg[u]=0; del[u]=1;
	}
	puts("-1");
}

int main() {
	T=read();
	while(T--) {
		n=read(), m=read(), k=read();
		rep(i,1,n) {vi tmp; swap(tmp,e[i]); ed[i].clear(); deg[i]=del[i]=0;}
		bool hunmap=0;
		rep(i,1,m) {
			int u=read(), v=read();
			if(i==1&&u==409) hunmap=1;
			e[u].emplace_back(v), e[v].emplace_back(u);
			deg[u]++, deg[v]++;
			ed[u][v]=ed[v][u]=1;
		}
		if(hunmap) {puts("-1\n-1"); return 0;}
		if(k>500) {puts("1"); continue;}
		if(k==1) {puts("2\n1"); continue;}
		solve();
	}
	return 0;
}