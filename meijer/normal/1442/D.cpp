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
 
const int MX = 4000;

int n, k;
int t[MX];
vll a[MX];
vll sm[MX];

ll getAns(vll dp, int l, int r) {
    ll ans = 0;

    if(l == r) {
        ll cursm = 0;
        RE(i,k+1) {
            ans = max(ans, dp[k-i]+cursm);
            if(i >= t[l]) break;
            cursm += a[l][i];
        }
        return ans;
    }

    int m=(l+r)/2;

    // left
    {
        vll ndp = dp;
        REP(i,m+1,r+1) {
            // add i to dp
            ll len = min(k,t[i]);
            ll s = sm[i][len-1];
            REV(j,len,k+1) ndp[j] = max(ndp[j], ndp[j-len]+s);
        }
        ans = max(ans, getAns(ndp, l, m));
    }

    // right
    {
        vll ndp = dp;
        REP(i,l,m+1) {
            // add i to dp
            ll len = min(k,t[i]);
            ll s = sm[i][len-1];
            REV(j,len,k+1) ndp[j] = max(ndp[j], ndp[j-len]+s);
        }
        ans = max(ans, getAns(ndp, m+1, r));
    }

    return ans;
}

void program() {
    IN(n,k);
    RE(i,n) {
        IN(t[i]); a[i].resize(t[i]);
        RE(j,t[i]) IN(a[i][j]);
    }
    RE(i,n) {
        sm[i].resize(t[i]);
        sm[i][0] = a[i][0];
        REP(j,1,t[i]) sm[i][j] = sm[i][j-1]+a[i][j];
    }

    ll ans = getAns(vll(k+1,0), 0, n-1);
    OUTL(ans);
}