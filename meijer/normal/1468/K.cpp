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

int t, n;
string s;
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};

bool tryObs(int ox, int oy) {
    int cx = 0, cy = 0;
    RE(i,n) {
        int nx = cx + dx[s[i]];
        int ny = cy + dy[s[i]];
        if(nx == ox && ny == oy)
            continue;
        cx = nx, cy = ny;
    }
    return cx == 0 && cy == 0;
}

void program() {
    IN(t);
    while(t--) {
        IN(s); n=s.size();
        RE(i,n) {
            if(s[i] == 'L') s[i] = 0;
            if(s[i] == 'U') s[i] = 1;
            if(s[i] == 'R') s[i] = 2;
            if(s[i] == 'D') s[i] = 3;
        }

        int cx=0, cy=0;
        bool found = 0;
        RE(i,n) {
            cx += dx[s[i]];
            cy += dy[s[i]];
            if(tryObs(cx,cy)) {
                found = 1;
                OUTLS(cx,cy);
                break;
            }
        }
        if(!found)
            OUTLS(0,0);
    }
}