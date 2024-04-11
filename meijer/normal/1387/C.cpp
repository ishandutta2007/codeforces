
#include <bits/stdc++.h>
using namespace std;

// macros
typedef unsigned long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ll, ll> lll;
typedef tuple<int, int, int> iii;
typedef tuple<ll, ll, ll, ll> iiii;
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
#define EPS 1e-9
#define pb push_back
#define popb pop_back
#define fi first
#define se second
#define sz size()
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// input
template<class T> void IN(T& x) {cin >> x;}
template<class H, class... T> void IN(H& h, T&... t) {IN(h); IN(t...); }
template<class H> void INA(H bg, H ed) {while(bg != ed) IN(*bg++);}

// output
template<class T> void OUT(const T& x) {cout << x;}
template<class H, class... T> void OUT(const H& h, const T&... t) {OUT(h); OUT(t...); }

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

const int MX = 300;
ll INF = (1ll<<63ll)+(1ll<<62ll);
int og, g, n, m;
int a[MX], k[MX], b[MX][MX];
int l[MX], c[MX][MX], suml;
ll dp[MX][MX][MX];
priority_queue<iiii, vector<iiii>, greater<iiii>> pq;
vi rev[MX];

int getNextState(string t) {
    int x=0, ans=0, longest=0;
    RE(i,m) {
        string s;
        RE(j,l[i]) {
            if(s.sz > longest && s.sz <= t.sz) {
                bool pos = 1;
                RE(k,s.sz) if(t[t.sz-k-1] != s[s.sz-k-1]) {
                    pos=0;
                    break;
                }
                if(pos) longest = s.sz, ans=x;
            }
            s += '0'+c[i][j];
            x++;
        }
        if(s.sz <= t.sz) {
            bool pos = 1;
            RE(k,s.sz) if(t[t.sz-k-1] != s[s.sz-k-1]) {
                pos=0;
                break;
            }
            if(pos) return suml;
        }
    }
    return ans;
}
void fillDpBase() {
    int x=0;
    RE(i,m) {
        string s;
        RE(j,l[i]) {
            dp[0][x][getNextState(s+"0")] = 1;
            dp[1][x][getNextState(s+"1")] = 1;
            s += '0'+c[i][j];
            x++;
        }
    }
    if(m == 0) {
        dp[0][0][0] = 1;
        dp[1][0][0] = 1;
    }
}

void program() {
    IN(g,n,m); og=g;
    RE(i,n) IN(a[i]), IN(k[i]), INA(b[i], b[i]+k[i]);
    RE(i,m) IN(l[i]), INA(c[i], c[i]+l[i]);

    // change transitions so k <= 2
    RE(i,n) {
        if(k[i] > 2) {
            a[n] = g;
            k[n] = k[i]-1;
            RE(j,k[n]) b[n][j] = b[i][j];
            b[i][0] = g; b[i][1] = b[i][k[i]-1];
            k[i] = 2;
            g++; n++;
        }
    }

    // fill rev
    RE(i,n) RE(j,k[i]) rev[b[i][j]].pb(i);

    // set initial dp
    RE(i,m) suml += l[i];
    if(m == 0) suml = 1;
    RE(i,g) RE(j,suml) RE(k,suml) dp[i][j][k]=INF;
    fillDpBase();

    // fill dp
    RE(i,2) RE(j,suml) RE(k,suml) pq.push({dp[i][j][k], i, j, k});
    while(!pq.empty()) {
        iiii p = pq.top(); pq.pop();
        ll X, I, J, K;
        tie(X, I, J, K) = p;
        if(X == INF) break;
        if(dp[I][J][K] != X) continue;
        FOR(i,rev[I]) {
            if(k[i] == 1) {
                if(dp[a[i]][J][K] > X) {
                    dp[a[i]][J][K] = X;
                    pq.push({X, a[i], J, K});
                }
            } else {
                if(b[i][0] == I) {
                    RE(j,suml) {
                        if(dp[b[i][1]][K][j] == INF) continue;
                        ll Y = X + dp[b[i][1]][K][j];
                        if(dp[a[i]][J][j] > Y) {
                            dp[a[i]][J][j] = Y;
                            pq.push({Y, a[i], J, j});
                        }
                    }
                }
                if(b[i][1] == I) {
                    RE(j,suml) {
                        if(dp[b[i][0]][j][J] == INF) continue;
                        ll Y = dp[b[i][0]][j][J] + X;
                        if(dp[a[i]][j][K] > Y) {
                            dp[a[i]][j][K] = Y;
                            pq.push({Y, a[i], j, K});
                        }
                    }
                }
            }
        }
    }

    // print answers
    REP(i,2,og) {
        ll mn = INF;
        RE(j,suml) mn = min(mn, dp[i][0][j]);
        if(mn == INF) OUT("YES\n");
        else OUT("NO ",mn,"\n");
    }
}