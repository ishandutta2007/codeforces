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
 
const int MX = 5000;
const int N = (1<<20);

int n,k;
int cost[MX][MX];
int dp[MX][MX];
int sm[MX][MX];

int getCost(int l, int r) {
    r++;
    return sm[r][r] - sm[l][r] - sm[r][l] + sm[l][l];
}
void daq(int j, int l, int r, int al, int ar) {
    if(l > r) return;
    int mid=(l+r)/2;

    int res=2e9, bestM=0;
    REP(i,al,ar+1) {
        int nRes = cost[i][mid] + (i == 0 ? 0 : dp[i-1][j-1]);
        if(nRes < res) {
            res = nRes;
            bestM = i;
        }
    }
    dp[mid][j] = res;

    daq(j,l,mid-1,al,bestM);
    daq(j,mid+1,r,bestM,ar);
}

void program() {
    IN(n,k);
    RE1(i,n) RE1(j,n) {
        char c; IN(c);
        sm[i][j] = c-'0';
    }
    RE(i,n+1) RE(j,n+1) {
        if(i   ) sm[i][j] += sm[i-1][j  ];
        if(   j) sm[i][j] += sm[i  ][j-1];
        if(i&&j) sm[i][j] -= sm[i-1][j-1];
    }
    RE(i,n+1) RE(j,n+1) cost[i][j] = getCost(i,j)/2;
    RE(i,n) dp[i][0] = cost[0][i];
    REP(j,1,k) daq(j,0,n-1,0,n-1);

    OUTL(dp[n-1][k-1]);
}