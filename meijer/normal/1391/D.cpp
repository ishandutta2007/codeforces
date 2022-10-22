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

const int MX = 1e6+10;

int n, m;
string s[MX];
bitset<MX> a[3];
int dp[MX][8];

bool possible(int a, int b) {
    bool x[2][3];
    RE(i,n) x[0][i] = (a&(1<<i))!=0;
    RE(i,n) x[1][i] = (b&(1<<i))!=0;
    RE(bx,(n-1)) {
        bool X=0;
        RE(i,2) RE(j,2) X ^= x[j][bx+i];
        if(!X) return 0;
    }
    return 1;
}
int getAns(int i, int j) {
    if(dp[i][j] != -1) return dp[i][j];

    int ans = INF;

    if(i == 0) {
        RE(nj,(1<<n)) {
            if(possible(nj,j)) {
                int changed = 0;
                RE(x,n) if(a[x][i] != bool((nj&(1<<x))!=0)) changed++;
                ans = min(ans, changed);
            }
        }
    } else {
        RE(nj,(1<<n)) {
            if(possible(nj,j)) {
                int changed = 0;
                RE(x,n) if(a[x][i] != bool((nj&(1<<x))!=0)) changed++;
                ans = min(ans, getAns(i-1,nj)+changed);
            }
        }
    }

    return dp[i][j] = ans;
}

void program() {
    IN(n,m);
    RE(i,n) IN(s[i]);
    if(n >= 4 && m >= 4) {
        OUTL(-1);
        return;
    }
    if(n <= 3) {
        RE(i,n) RE(j,m) a[i][j] = (s[i][j])-'0';
    } else {
        RE(i,n) RE(j,m) a[j][i] = (s[i][j])-'0';
        swap(n,m);
    }
    RE(i,m) RE(j,8) dp[i][j] = -1;
    int ans = INF;
    RE(i,(1<<n)) ans = min(ans, getAns(m-1,i));
    OUTL(ans);
}