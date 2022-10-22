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

int testCases;

ll gcd(ll a, ll b) {return b == 0 ? a : gcd(b,a%b);}
vll getFactors(ll x) {
    vll ans;
    for(ll i=2; i*i<=x; i++) {
        if(x%i == 0) ans.pb(i);
        while(x%i == 0) {
            x /= i;
        }
    }
    if(x > 1) ans.pb(x);
    if(ans.empty()) ans.pb(1);
    return ans;
}
ll count(ll x, ll y) {
    ll cnt = 0;
    while(x%y == 0) {
        x/=y;
        cnt++;     
    }
    return cnt;
}
ll pow(ll x, ll y) {
    ll res = 1;
    RE(i,y) res *= x;
    return res;
}


void program() {
    IN(testCases);
    while(testCases--) {
        ll p, q; IN(p,q);
        vll f = getFactors(q);
        ll ans = 1;
        FOR(i,f) {
            ll cntp = count(p, i);
            ll cntq = count(q, i);
            if(cntp < cntq) {
                ans = p;
            } else {
                ans = max(ans, p/pow(i,cntp-cntq+1));
            }
        }
        OUTL(ans);
    }
}