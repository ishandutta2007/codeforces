#include <bits/stdc++.h>
using namespace std;
 
// macros
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ll, ll> lll;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<ll> vll;
typedef vector<lll> vlll;
#define REP(a,b,c) for(int a=int(b); a<int(c); a++)
#define RE(a,c) REP(a,0,c)
#define RE1(a,c) REP(a,1,c+1)
#define REI(a,b,c) REP(a,b,c+1)
#define REV(a,b,c) for(int a=int(c-1); a>=int(b); a--)
#define FOR(a,b) for(auto& a : b)
#define all(a) a.begin(), a.end()
#define INF 1e9
#define EPS 1e-9
#define pb push_back
#define popb pop_back
#define fi first
#define se second
#define sz size()
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
 
// input
template<class T> void IN(T& x) {cin >> x;}
template<class H, class... T> void IN(H& h, T&... t) {IN(h); IN(t...); }
 
// output
template<class T1, class T2> void OUT(const pair<T1,T2>& x);
template<class T> void OUT(const vector<T>& x);
template<class T> void OUT(const T& x) {cout << x;}
template<class H, class... T> void OUT(const H& h, const T&... t) {OUT(h); OUT(t...); }
template<class T1, class T2> void OUT(const pair<T1,T2>& x) {OUT(x.fi,' ',x.se);}
template<class T> void OUT(const vector<T>& x) {RE(i,x.size()) OUT(i==0?"":" ",x[i]);}
template<class... T> void OUTL(const T&... t) {OUT(t..., "\n"); }
template<class H> void OUTLS(const H& h) {OUTL(h); }
template<class H, class... T> void OUTLS(const H& h, const T&... t) {OUT(h,' '); OUTLS(t...); }
 
//===================//
//  Added libraries  //
//===================//
 
//===================//
//end added libraries//
//===================//
 
void program();
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    program();
}
 
 
//===================//
//   begin program   //
//===================//
 
const int MX = 5e5;

int n;
int k, a[MX];
vi adj[MX];
int dist[MX];
int ans[MX];
int d2[MX];

void program() {
    IN(n);
    RE(i,n-1) {
        int u, v; IN(u,v);
        adj[u].pb(v);
        adj[v].pb(u);
    }
    IN(k);
    RE(i,k) IN(a[i]);

    RE1(i,n) dist[i]=INF;
    queue<int> q;
    RE(i,k) q.push(a[i]), dist[a[i]]=0;
    while(!q.empty()) {
        int u = q.front(); q.pop();
        FOR(v,adj[u]) {
            if(dist[v] == INF) {
                dist[v] = dist[u]+1;
                q.push(v);
            }
        }
    }

    RE1(i,n) ans[i] = -1;
    vii seq;
    RE1(i,n) seq.pb({dist[i],i});
    RE1(i,n) d2[i] = -1;
    sort(all(seq),greater<ii>());
    RE(_,seq.size()) {
        int rt = seq[_].second;
        if(d2[rt] < dist[rt]) {
            priority_queue<ii> pq;
            pq.push({dist[rt],rt}); ans[rt]=max(ans[rt], d2[rt]=dist[rt]);
            while(!pq.empty()) {
                ii p=pq.top(); pq.pop();
                int u=p.se;
                if(d2[u] != p.fi) continue;
                FOR(v,adj[u]) {
                    if(d2[u] > 1  && d2[u]-1 > d2[v]) {
                        d2[v] = d2[u]-1;
                        ans[v] = max(ans[v], dist[rt]);
                        pq.push({d2[v],v});
                    }
                }
            }
        }
    }

    RE1(i,n) OUT(i==1?"":" ", ans[i]); OUTL();
}