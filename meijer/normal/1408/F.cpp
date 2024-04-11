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
vii ans;

void program() {
    IN(n);
    
    int N = 1;
    while(N < n) N *= 2;

    stack<vi> stck;
    vi nxt;
    REP(i,1,N+1) {
        int j = ((i-1)%n)+1;
        nxt.pb(j);
        while(!stck.empty() && stck.top().size() == nxt.size()) {
            vi prev = stck.top(); stck.pop();
            vi nw;
            RE(i,nxt.size()) {
                ans.pb({nxt[i], prev[i]});
                nw.pb(nxt[i]);
                nw.pb(prev[i]);
            }
            nxt = nw;
            if(i == N && stck.size() == 1) break;
        }
        stck.push(nxt);
        nxt.clear();
    }

    OUTL(ans.size());
    RE(i,ans.size()) OUTL(ans[i]);
}