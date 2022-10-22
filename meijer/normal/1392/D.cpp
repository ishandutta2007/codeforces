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
template<class T> void OUT(const T& x) {cout << x;}
template<class H, class... T> void OUT(const H& h, const T&... t) {OUT(h); OUT(t...); }
template<class T1, class T2> void OUT(const pair<T1,T2>& x) {OUT(x.fi,' ',x.se);}
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
int n;
string s;
int a[MX];
int dp[MX][4];
int curCon;

int getAns(int i, int ar) {
    if(dp[i][ar] != -1) return dp[i][ar];

    int ans = INF;
    if(i == n) {
        if(ar == curCon)
            ans = 0;
    } else {
        if(ar == 0) { // player to the left is attacking to the left, and is being attacked from the left
            ans = min(ans, getAns(i+1, 1) + int(a[i] != 0));
            ans = min(ans, getAns(i+1, 3) + int(a[i] != 1));
        } else if(ar == 1) {
            // player to the left is attacking to the left, but is not being attacked from the left
            ans = min(ans, getAns(i+1, 3) + int(a[i] != 1));
        } else if(ar == 2) {
            // player to the left is attacking to the right, and is being attacked from the left
            ans = min(ans, getAns(i+1, 0) + int(a[i] != 0));
        } else if(ar == 3) {
            // player to the left is attacking to the right, but is not being attacked from the left
            ans = min(ans, getAns(i+1, 0) + int(a[i] != 0));
            ans = min(ans, getAns(i+1, 2) + int(a[i] != 1));
        }
    }

    return dp[i][ar] = ans;
}

void program() {
    IN(testCases);
    while(testCases--) {
        IN(n,s);
        RE(i,n) a[i] = (s[i]=='R');

        int ans = INF;
        RE(j,4) {
            curCon = j;
            RE(i,n+1) RE(k,4) dp[i][k] = -1;
            ans = min(ans, getAns(0,j));
        }
        OUTL(ans);
    }
}