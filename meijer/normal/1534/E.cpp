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
#define INF 1e18
#define EPS 1e-9
#define pb push_back
#define popb pop_back
#define fi first
#define se second
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
 
// dp
template<class T> bool ckmin(T&a, T&b) { bool bl = a > b; a = min(a,b); return bl;}
template<class T> bool ckmax(T&a, T&b) { bool bl = a < b; a = max(a,b); return bl;}
 
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
const int N = (1<<20);

int n, k, a[MX];

int query(vi v) {
    OUTLS("?",v);
    cout.flush();
    int res; IN(res);
    return res;
}

int dist[MX], pre[MX];
vi adj[MX];

void program() {
    IN(n,k);

    RE(i,n+1) {
        int cnt1=i, cnt2=n-i;

        RE(j,min(k+1,i+1)) {
            if((k-j) > cnt2) continue;
            int v = cnt1 - j + (k-j);
            adj[i].pb(v);
        }

        dist[i] = -1;
    }

    dist[0] = 0;
    queue<int> q; q.push(0);
    while(!q.empty()) {
        int u = q.front(); q.pop();
        FOR(v,adj[u]) {
            if(dist[v] != -1) continue;
            dist[v] = dist[u] + 1;
            pre[v] = u;
            q.push(v);
        }
    }

    if(dist[n] == -1) {
        OUTL(-1);
        cout.flush();
        return;
    }

    int ans = 0;
    vi even, odd;
    RE1(i,n) even.pb(i);
    while(!even.empty()) {
        int a;
        RE(j,min<int>(k+1,even.size()+1)) {
            int v = even.size() - j + (k-j);
            if(v == pre[even.size()])
                a = j;
        }
        int b = k - a;

        vi addE, addO;
        vi ask;
        RE(i,a) addO.pb(even.back()), ask.pb(even.back()), even.pop_back();
        RE(i,b) addE.pb(odd.back()), ask.pb(odd.back()), odd.pop_back();
        ans ^= query(ask);
        FOR(i,addE) even.pb(i);
        FOR(i,addO) odd .pb(i);
    }

    OUTLS("!",ans);
    cout.flush();
}