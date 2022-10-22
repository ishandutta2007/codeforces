#include <bits/stdc++.h>
using namespace std;
 
// macros
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ll, ll> lll;
typedef tuple<int, int, int> iii;
typedef tuple<int, int, int, int> iiii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<iiii> viiii;
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
 
const int MX = 7e5;

int testCases;
int h, v, l[MX], p[MX];
int a[MX], n;

bitset<MX> found[1001];
bitset<MX> dp[1001];
vi A, B;
vi AL, BL;
vi AP, BP;
bool getAns(int w, int i) {
    if(w < 0) return 0;
    if(w == 0) return 1;
    if(i == n) return 0;
    if(found[i][w])
        return dp[i][w];
    
    bool res = 0;
    if(getAns(w,i+1)) res = 1; // dont pick i
    if(getAns(w-a[i],i+1)) res = 1; // pick i

    found[i][w] = 1;
    return dp[i][w] = res;
}
void fillAns(int w, int i) {
    if(i == n) return;
    if(getAns(w,i+1)) {
        A.pb(a[i]);
        fillAns(w,i+1);
    } else {
        B.pb(a[i]);
        fillAns(w-a[i],i+1);
    }
}

void program() {
    IN(testCases);
    while(testCases--) {
        IN(h);
        RE(i,h) IN(l[i]);
        IN(v);
        RE(i,v) IN(p[i]);
        if(h != v) {
            OUTL("No");
            continue;
        }
        n = h;
        sort(l,l+n,greater<int>());
        sort(p,p+n,greater<int>());

        // find l
        A.clear(); B.clear();
        RE(i,n) found[i].reset();
        RE(i,n) dp[i].reset();
        int totL = 0;
        RE(i,n) totL += l[i];
        RE(i,n) a[i] = l[i];
        if((totL%2)==1 || !getAns(totL/2,0)) {
            OUTL("No");
            continue;
        }
        fillAns(totL/2,0);
        AL = A;
        BL = B;

        // find p
        A.clear(); B.clear();
        RE(i,n) found[i].reset();
        RE(i,n) dp[i].reset();
        int totP = 0;
        RE(i,n) totP += p[i];
        RE(i,n) a[i] = p[i];
        if((totP%2)==1 || !getAns(totP/2,0)) {
            OUTL("No");
            continue;
        }
        fillAns(totP/2,0);
        AP = A;
        BP = B;

        if(AL.size() > BL.size()) swap(AL,BL);
        if(AP.size() < BP.size()) swap(AP,BP);
        sort(all(AL), greater<int>());
        sort(all(AP));
        sort(all(BL), greater<int>());
        sort(all(BP));
        A.clear(); B.clear();
        FOR(i,AL) A.pb(i);
        FOR(i,BL) A.pb(-i);
        FOR(i,AP) B.pb(i);
        FOR(i,BP) B.pb(-i);


        viiii segments;
        int x=0, y=0;
        RE(i,n) {
            segments.pb({x,y,x+A[i],y});
            x += A[i];
            segments.pb({x,y,x,y+B[i]});
            y += B[i];
        }

        bool pos = 1;
        FOR(i,segments) FOR(j,segments) {
            int x1, y1, x2, y2;
            int x3, y3, x4, y4;
            tie(x1,y1,x2,y2) = i;
            tie(x3,y3,x4,y4) = j;
            bool hCol = (x2 >= x3 && x2 <= x4) || (x1 >= x3 && x1 <= x4);
            bool vCol = (y2 >= y3 && y2 <= y4) || (y1 >= y3 && y1 <= y4);
            bool hCol2 = (x2 > x3 && x2 < x4) || (x1 > x3 && x1 < x4);
            bool vCol2 = (y2 > y3 && y2 < y4) || (y1 > y3 && y1 < y4);
            if(hCol2 && vCol) pos = 0;
            if(hCol && vCol2) pos = 0;
        }

        if(!pos) {
            OUTL("No");
            continue;
        }

        OUTL("Yes");
        x=0, y=0;
        RE(i,n) {
            x += A[i];
            OUTLS(x,y);
            y += B[i];
            OUTLS(x,y);
        }
    }
}