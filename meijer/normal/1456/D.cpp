#include <bits/stdc++.h>
using namespace std;
 
// macros
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ll, ll> lll;
typedef tuple<ll, ll, ll> llll;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<ll> vll;
typedef vector<lll> vlll;
typedef vector<llll> vllll;
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
 
const int MX = 5006;

int n;
ll t[MX], x[MX];
ll minTime[MX]; // minimal time to go to x, with all cakes before x collected
bool pos[MX][MX]; // we just collected x with a clone at y

ll dist(ll i, ll j) {
    return abs(x[i]-x[j]);
}

void program() {
    RE(i,MX) minTime[i] = INF;
    RE(i,MX) RE(j,MX) pos[i][j]=0;

    IN(n);
    t[0] = 0, x[0] = 0;
    RE1(i,n) IN(t[i], x[i]);
    n++;

    minTime[0] = 0;
    pos[0][0] = 1;

    RE(i,n) {
        if(minTime[i] <= t[i]) {
            // leave clone at i, go to i+1, put clone at i+1
            minTime[i+1] = min(minTime[i+1], max(t[i], minTime[i]+dist(i,i+1)));

            // leave clone at i, go to j, leave clone at j, go to i+1
            RE(j,n) {
                ll timeAtJ = max(t[i], minTime[i]+dist(i,j));
                if(timeAtJ+dist(j,i+1) <= t[i+1]) {
                    pos[i+1][j] = 1;
                }
            }
        }
        RE(j,n) {
            if(pos[i][j]) {
                if(i+1 == j) { // clone is at next position
                    // leave clone at i+1, go to i+2, put clone at i+2
                    minTime[i+2] = min(minTime[i+2], max(t[i+1], t[i]+dist(i,i+2)));

                    // leave clone at i+1, go to k, put clone at k, go to i+2
                    RE(k,n) {
                        ll timeAtK = max(t[j], t[i]+dist(i,k));
                        if(timeAtK+dist(k,i+2) <= t[i+2]) {
                            pos[i+2][k] = 1;
                        }
                    }
                } else {
                    // leave clone at j, go to i
                    if(t[i]+dist(i,i+1) <= t[i+1]) {
                        pos[i+1][j] = 1;
                    }
                }
            }
        }
    }

    bool ans = 0;
    if(minTime[n-1] <= t[n-1]) ans=1;
    if(pos[n-2][n-1]) ans=1;
    OUTL(ans?"YES":"NO");
}