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
template<class T1, class T2> void OUT(const pair<T1,T2>& x) {OUT(x.fi," ",x.se);}
template<class... T> void OUTL(const T&... t) {OUT(t..., "\n"); }

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

const int MX = 2100, BIT=11;
int n, m;
string gr[MX];
int mxr[MX][MX], mxl[MX][MX][BIT];
int number[1<<BIT+1], MSB[1<<BIT+1];
int dp[MX][MX];

bool inside(int x, int y) {return x>=0 && x<n && y>=0 && y<m;}
int msb(int x) {
    int ans = 0; 
    while(x) { 
        x = x>>1;
        ans++;
    } 
    return ans-1;
}
bool possible(int x, int y, int r) {
    if(r == 0) return 1;
    int r0=r;
    if(!inside(x+r-1,y+r-1)) return 0;
    if(mxl[x][y][MSB[r]] < r0) return 0;
    x+=r-(1<<MSB[r]);
    y+=r-(1<<MSB[r]);
    if(mxl[x][y][MSB[r]] < r0) return 0;
    return 1;
}

void program() {
    IN(n,m);
    RE(i,n) IN(gr[i]);
    RE(i,BIT) number[1<<i]=i;
    RE(i,(1<<BIT)+1) MSB[i] = msb(i);
    REV(x,0,n) REV(y,0,m) {
        int nx=x+1, ny=y+1;
        if(!inside(nx,ny)) mxr[x][y] = 1;
        else mxr[x][y] = 1+(gr[x][y]==gr[nx][ny] ? mxr[nx][ny] : 0);
    }
    REV(x,0,n) REV(y,0,m) {
        int nx=x+1, ny=y-1;
        if(!inside(nx,ny)) mxl[x][y][0] = 1;
        else mxl[x][y][0] = 1+(gr[x][y]==gr[nx][ny] ? mxl[nx][ny][0] : 0);
    }
    RE(i,BIT-1) {
        REV(x,0,n) REV(y,0,m) {
            int nx=x+(1<<i), ny=y+(1<<i);
            if(!inside(nx,ny)) mxl[x][y][i+1] = 0;
            else mxl[x][y][i+1] = min(mxl[x][y][i],mxl[nx][ny][i]);
        }
    }
    ll ans = 0;
    REV(x,0,n) {
        REV(y,0,m) {
            int lb=1, ub=mxr[x][y];
            if(x != n-1) {
                if(gr[x][y]!=gr[x+1][y]) ub=1;
                ub=min(ub, dp[x+1][y]+1);
            }
            while(lb != ub) {
                int mid=(lb+ub+1)/2;
                if(possible(x,y,mid)) lb=mid;
                else ub=mid-1;
            }
            ans += lb;
            dp[x][y] = lb;
        }
    }
    OUTL(ans);
}