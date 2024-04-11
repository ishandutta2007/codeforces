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
 
const int N = (1<<20);

int testCases;
int n, a[N];


 
ii seg[N*2];
int laz[N*2];
 
void setSeg(int i, int v, int lazy=0, int p=1, int l=0, int r=N-1) {
    seg[p].fi += lazy;
    laz[p] += lazy;
    if(i < l || i > r) return;
    if(l == r) {
        seg[p].fi = v;
        seg[p].se = l;
        return;
    }
    int m=(l+r)/2;
    setSeg(i,v,laz[p],p*2,l,m);
    setSeg(i,v,laz[p],p*2+1,m+1,r);
    laz[p] = 0;
    seg[p] = min(seg[p*2], seg[p*2+1]);
}
void addSeg(int i, int j, int v, int lazy=0, int p=1, int l=0, int r=N-1) {
    seg[p].fi += lazy;
    laz[p] += lazy;
    if(j < l || i > r) return;
    if(i <= l && j >= r) {
        seg[p].fi += v;
        laz[p] += v;
        return;
    }
    int m=(l+r)/2;
    addSeg(i,j,v,laz[p],p*2,l,m);
    addSeg(i,j,v,laz[p],p*2+1,m+1,r);
    laz[p] = 0;
    seg[p] = min(seg[p*2], seg[p*2+1]);
}
ii getSeg(int i, int j, int lazy=0, int p=1, int l=0, int r=N-1) {
    seg[p].fi += lazy;
    laz[p] += lazy;
    if(j < l || i > r) return {INF, INF};
    if(i <= l && j >= r) return seg[p];
    int m=(l+r)/2;
    ii a=getSeg(i,j,laz[p],p*2,l,m);
    ii b=getSeg(i,j,laz[p],p*2+1,m+1,r);
    laz[p]=0;
    return min(a,b);
}

void program() {
    IN(testCases);
    while(testCases--) {
        IN(n);
        RE(i,n) IN(a[i]);
        RE(i,n) setSeg(i,a[i]);

        
        int x1 = 0, x2 = n-1;
        REP(i,1,n) {
            if(a[i] > a[i-1]) break;
            x1 = i;
        }
        REV(i,0,n-1) {
            if(a[i] > a[i+1]) break;
            x2 = i;
        }

        while(x2 != 0) {
            ii p = getSeg(0,x2-1);
            int remove = getSeg(x2-1,x2-1).fi - getSeg(x2,x2).fi;
            if(remove <= 0) break;
            addSeg(0,x2-1,-remove);
            while(getSeg(x2-1,x2-1).fi <= getSeg(x2,x2).fi) {
                x2--;
            }
        }
 
        bool pos = 1;
        int lst = 0;
        RE(i,n) {
            int nw = getSeg(i,i).fi;
            if(nw < lst) pos = 0;
            lst = nw;
        }
        OUTL(pos?"YES":"NO");
    }
}