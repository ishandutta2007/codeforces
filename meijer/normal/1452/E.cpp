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
 
const int MX = 5000;

int n, m, k;
int l[MX], r[MX], mid[MX];
int SA[MX];
int sml[MX][MX], smr[MX][MX];

int getIntersect(int L, int R, int M) {
    int ml = M-k+1;
    int mr = M+k;
    ml = max(ml,L);
    mr = min(mr,R);
    return max(0,mr-ml+1);
}

void program() {
    IN(n,m,k);
    RE(i,m) IN(l[i], r[i]);
    RE(i,m) l[i]=l[i]*2-1, r[i]*=2;
    RE(i,m) mid[i]=(l[i]+r[i])/2;
    n*=2;

    RE(i,m) SA[i]=i;
    sort(SA,SA+m, [](int i, int j) {
        return mid[i]<mid[j];
    });

    RE1(i,n) {
        // set point i as center
        sml[i][0] = 0;
        RE(j,m) {
            sml[i][j+1] = sml[i][j];
            sml[i][j+1] += getIntersect(l[SA[j]], r[SA[j]], i);
        }
        smr[i][m] = 0;
        REV(j,0,m) {
            smr[i][j] = smr[i][j+1];
            smr[i][j] += getIntersect(l[SA[j]], r[SA[j]], i);
        }
    }

    int ans = 0;
    RE(j,m+1) {
        int mxl = 0, mxr=0;
        RE1(i,n) mxl = max(mxl, sml[i][j]);
        RE1(i,n) mxr = max(mxr, smr[i][j]);
        ans = max(ans, mxl+mxr);
    }
    OUTL(ans/2);
}