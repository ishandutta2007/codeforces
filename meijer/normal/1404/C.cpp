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

const int MX = 6e5+5;

int n, q, a[MX];
int x[MX], y[MX];
int SX[MX];
int ans[MX];
int sm[MX];
int ex[MX];

int FT[MX];

void addFT(int i, int value) {
    for(i++; i<=n; i+=i&-i) FT[i] += value;
}
int getFT(int i) {
    int ans = 0;
    for(i++; i; i-=i&-i) ans += FT[i];
    return ans;
}


ii seg[MX*4]; int LAZY[MX*4];
void buildSeg(int p=0, int l=0, int r=n-1) {
    if(l == r) {
        seg[p] = {INF,l};
        LAZY[p] = 0;
        return;
    }
    int m=(l+r)/2;
    buildSeg(p*2+1,l,m);
    buildSeg(p*2+2,m+1,r);
    seg[p] = min(seg[p*2+1], seg[p*2+2]);
    LAZY[p] = 0;
}
void addSeg(int i, int j, int v, int lazy=0, int p=0, int l=0, int r=n-1) {
    seg[p].fi += lazy;
    LAZY[p] += lazy;
    if(j < l || i > r) return;
    if(i <= l && j >= r) {
        seg[p].fi += v;
        LAZY[p] += v;
        return;
    }
    int m=(l+r)/2;
    addSeg(i,j,v,LAZY[p],p*2+1,l,m);
    addSeg(i,j,v,LAZY[p],p*2+2,m+1,r);
    seg[p] = min(seg[p*2+1], seg[p*2+2]);
    LAZY[p] = 0;
}
void setSeg(int i, int v, int lazy=0, int p=0, int l=0, int r=n-1) {
    seg[p].fi += lazy;
    LAZY[p] += lazy;
    if(i < l || i > r) return;
    if(l == r) {
        seg[p].fi = v;
        return;
    }
    int m=(l+r)/2;
    setSeg(i,v,LAZY[p],p*2+1,l,m);
    setSeg(i,v,LAZY[p],p*2+2,m+1,r);
    seg[p] = min(seg[p*2+1], seg[p*2+2]);
    LAZY[p] = 0;
}
ii getSeg(int i, int j, int lazy=0, int p=0, int l=0, int r=n-1) {
    seg[p].fi += lazy;
    LAZY[p] += lazy;
    if(j < l || i > r) return {INF,INF};
    if(i <= l && j >= r) return seg[p];
    int m=(l+r)/2;
    ii a = getSeg(i,j,LAZY[p],p*2+1,l,m);
    ii b = getSeg(i,j,LAZY[p],p*2+2,m+1,r);
    seg[p] = min(seg[p*2+1], seg[p*2+2]);
    LAZY[p] = 0;
    return min(a,b);
}

void remove(int i) {
    addSeg(i,n-1,-1);
    setSeg(i,INF);
    ex[i] = 0;
    addFT(i,-1);

    ii p = seg[0];
    if(p.fi >= 0) return;
    remove(p.se);
}

void program() {
    IN(n,q);
    RE(i,n) IN(a[i]);
    RE(i,n) if(a[i] > i+1) a[i] = -n-1;
    RE(i,n) a[i] -= i+1;
    int curSm = 0;
    buildSeg();
    RE(i,n) FT[i] = 0;
    RE(i,n) {
        ex[i] = 0;
        if(-a[i] <= curSm) {
            setSeg(i, a[i]+curSm);
            curSm++, ex[i]=1;
            addFT(i,1);
        }
        sm[i] = curSm;
    }

    RE(i,q) IN(x[i], y[i]);

    RE(i,q) SX[i]=i;
    sort(SX,SX+q, [](int i, int j) {
        return x[i] < x[j];
    });

    int curX = 0;
    RE(i,q) {
        while(curX < x[SX[i]]) {
            if(ex[curX]) remove(curX);
            curX++;
        }
        ans[SX[i]] = getFT(n-y[SX[i]]-1);
    }

    RE(i,q) OUTL(ans[i]);
}