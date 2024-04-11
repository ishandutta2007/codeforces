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
#define INF (1e9+1e8)
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

int n, m;
int x[MX], y[MX];
int a[MX], b[MX];
map<int,set<int>> atX;
map<int,set<int>> atY;
set<int> difX, difY;
set<ii> dif;
map<ii,int> diag;

void program() {
    // input
    IN(n,m);
    RE(i,n) IN(x[i], y[i]);
    RE(i,m) IN(a[i], b[i]);
    x[n] = y[n] = INF; n++;
    RE(i,n) {
        atX[x[i]].insert(y[i]);
        atY[y[i]].insert(x[i]);
        difX.insert(x[i]);
        difY.insert(y[i]);
        dif.insert({x[i], y[i]});
    }

    // find losing positions
    int X=0, Y=0;
    while(X<=1e9) {
        if(dif.count({X,Y})) {
            X++;
            Y++;
            continue;
        }
        if(atX[X].size() && *atX[X].begin() <= Y) {
            X++;
            continue;
        }
        if(atY[Y].size() && *atY[Y].begin() <= X) {
            Y++;
            continue;
        }


        int lengthX = *difX.lower_bound(X) - X;
        int lengthY = *difY.lower_bound(Y) - Y;
        int length = min(lengthX, lengthY);
        length = max(length, 1);
        diag[{X,Y}] = length;
        X += length;
        Y += length;
    }

    // find answer
    RE(i,m) {
        bool win = 1;
        if(dif.count({a[i],b[i]})) win = 0;

        auto it = diag.lower_bound({a[i],INF});
        if(it != diag.begin()) {
            it--;
            int difX = a[i] - it->fi.fi;
            int difY = b[i] - it->fi.se;
            if(difX == difY && difX < it->se) win = 0;
        }

        OUTL(win ? "WIN" : "LOSE");
    }
}