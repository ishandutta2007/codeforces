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
 
const int MX = 5005;
const int N = (1<<20);

int testCases;
int n, m;
string gr[MX];
bitset<MX> allowed;
int dx4[]={1,-1,0,0};
int dy4[]={0,0,1,-1};
int dx[]={-1, 0, 1,-1, 0, 1,-1, 0, 1};
int dy[]={-1,-1,-1, 0, 0, 0, 1, 1, 1};
bool grid[3][3];

set<ii> q;

int p[MX*MX], r[MX*MX], sets;
void buildDSU(int dsuSize) {
    RE(i,dsuSize) p[i]=i, r[i]=0;
    sets = dsuSize;
}
int getSet(int i) {return i==p[i]?i:p[i]=getSet(p[i]);}
bool isSameSet(int i, int j) {return getSet(i)==getSet(j);}
void unionSet(int i, int j) {
    if(!isSameSet(i,j)) {
        i=p[i], j=p[j];
        sets--;
        if(r[i] > r[j]) {
            p[j] = i;
        } else {
            p[i] = j;
            if(r[i] == r[j]) r[j]++;
        }
    }
}

int f(int x, int y) {
    return x + y*n;
}


void fillAllowed() {
    RE(i,512) {
        RE(x,3) RE(y,3) grid[x][y] = 0;
        RE(j,9) if(i&(1<<j)) grid[1+dx[j]][1+dy[j]] = 1;
        if(grid[1][1]) continue;
        if(grid[0][0] && !grid[0][1] && !grid[1][0]) continue;
        if(grid[2][0] && !grid[2][1] && !grid[1][0]) continue;
        if(grid[0][2] && !grid[0][1] && !grid[1][2]) continue;
        if(grid[2][2] && !grid[2][1] && !grid[1][2]) continue;

        allowed[i] = 1;
    }
}
bool filled(int x, int y) {
    if(x < 0 || y < 0 || x >= n || y >= m) return 0;
    return gr[x][y] == 'X';
}
void update(int x, int y) {
    if(x < 0 || y < 0 || x >= n || y >= m) return;
    int bm = 0;
    RE(i,9) if(filled(x+dx[i], y+dy[i])) bm |= (1<<i);

    bool pos = allowed[bm];

    if(pos) {
        int set[4];
        RE(i,4) set[i] = -1-i;
        RE(i,4) if(filled(x+dx4[i], y+dy4[i])) set[i] = getSet(f(x+dx4[i], y+dy4[i]));
        RE(i,4) REP(j,i+1,4) if(set[i] == set[j]) pos = 0;
    }

    if(pos) q.insert({x,y});
    else q.erase({x,y});
}
void place(int x, int y) {
    q.erase({x,y});

    int set[4];
    RE(i,4) set[i] = -1-i;
    RE(i,4) if(filled(x+dx4[i], y+dy4[i])) set[i] = getSet(f(x+dx4[i], y+dy4[i]));
    RE(i,4) REP(j,i+1,4) if(set[i] == set[j]) return;

    gr[x][y] = 'X';
    RE(i,4) if(filled(x+dx4[i], y+dy4[i])) unionSet(f(x,y), f(x+dx4[i], y+dy4[i]));
    RE(i,9) update(x+dx[i], y+dy[i]);
}

void program() {
    IN(testCases);
    fillAllowed();
    while(testCases--) {
        IN(n,m);
        RE(i,n) IN(gr[i]);
        buildDSU(n*m);
        RE(i,n) RE(j,m) update(i,j);

        int cx = 1;
        while(cx < n) {
            RE(j,m) place(cx, j);
            cx += 3;
        }
        while(!q.empty()) {
            ii p = *q.begin();
            place(p.fi, p.se);
        }

        RE(i,n) OUTL(gr[i]);
    }
}