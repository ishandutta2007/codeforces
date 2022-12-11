#include <bits/stdc++.h>
#define va first
#define vb second
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pii,int> ppi;
typedef pair<int,pii> pip;

const int MN = 5e5+5;
const int MOD = 1e9+7;
const int INF = 1e9;

int p[MN],a[MN],b[MN],q[MN],c[MN],par[MN],pos[MN],l[MN],r[MN];
pii seg[MN<<2];
bool ch[MN];
vector<int> V[MN];

int fnd(int u)
{
	return u==par[u] ? u : fnd(par[u]);
}

void join(int u, int v)
{
	u = fnd(u), v = fnd(v);
	if(u==v) return;
	if(V[u].size()<V[v].size()) swap(u,v);
	for(int x:V[v]) V[u].push_back(x);
	par[v] = u;
}

void upt(int s, int e, int x, int v, int i)
{
	if(s==e){
		seg[i] = pii(v,x);
		return;
	}
	int m = (s+e)/2;
	if(x<=m) upt(s,m,x,v,i<<1);
	else upt(m+1,e,x,v,i<<1|1);
	seg[i] = max(seg[i<<1],seg[i<<1|1]);
}

pii qu(int s, int e, int x, int y, int i)
{
	if(e<x||y<s) return pii(-1,0);
	if(x<=s&&e<=y){
		return seg[i];
	}
	int m = (s+e)/2;
	return max(qu(s,m,x,y,i<<1),qu(m+1,e,x,y,i<<1|1));
}

int main()
{
	#ifdef L0TUS
    freopen("C:\\Users\\SKYPC364\\Documents\\Coding\\BOJ\\input.txt", "r", stdin);
    freopen("C:\\Users\\SKYPC364\\Documents\\Coding\\BOJ\\output.txt", "w", stdout);
	#endif
	
    ios_base::sync_with_stdio(0),cin.tie(0);

    int N,M,Q;
    cin >> N >> M >> Q;
    for(int i=1; i<=N; i++){
    	cin >> p[i];
    	par[i] = i;
    	V[i].push_back(i);
    }
    for(int i=1; i<=M; i++) cin >> a[i] >> b[i];
    for(int i=0; i<Q; i++){
    	cin >> q[i] >> c[i];
    	if(q[i]==2) ch[c[i]] = 1;
    }
    for(int i=1; i<=M; i++){
    	if(ch[i]) continue;
    	join(a[i],b[i]);
    }
    for(int i=Q-1; i>=0; i--){
    	if(q[i]==1){
    		int v = fnd(c[i]);
    		l[i] = V[v].front();
    		r[i] = V[v].back();
    	}
    	if(q[i]==2){
    		int e = c[i];
    		join(a[e],b[e]);
    	}
    }
    int cnt = 0;
    for(int i=1; i<=N; i++){
    	if(par[i]==i){
    		for(int x:V[i]) pos[x] = ++cnt;
    	}
    }
    
    for(int i=1; i<=N; i++){
    	upt(1,N,pos[i],p[i],1);
    }
    for(int i=0; i<Q; i++){
    	if(q[i]==1){
    		pii p = qu(1,N,pos[l[i]],pos[r[i]],1);
    		cout << p.va << '\n';
    		upt(1,N,p.vb,0,1);
    	}
    }
}