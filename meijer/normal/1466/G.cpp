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
 

// mod library
ll MOD=1e9+7;

inline ll mod(ll x_) {
    return (x_)%MOD;
}
ll modpow(ll x_, ll N_) {
    if(N_ == 0) return 1;
    ll a = modpow(x_,N_/2);
    a = (a*a)%MOD;
    if(N_%2) a = (a*x_)%MOD;
    return a;
}
ll inv(ll x_) {
    return modpow(x_, MOD-2);
}
class mi {
public:
    mi(ll v=0) {value = v;}
    mi  operator+ (ll rs) {return mod(value+rs);}
    mi  operator- (ll rs) {return mod(value-rs+MOD);}
    mi  operator* (ll rs) {return mod(value*rs);}
    mi  operator/ (ll rs) {return mod(value*inv(rs));}
    mi& operator+=(ll rs) {*this = (*this)+rs; return *this;}
    mi& operator-=(ll rs) {*this = (*this)-rs; return *this;}
    mi& operator*=(ll rs) {*this = (*this)*rs; return *this;}
    mi& operator/=(ll rs) {*this = (*this)/rs; return *this;}
    operator ll&() {return value;}

    ll value;
};
typedef vector<mi> vmi;

//===================//
//   begin program   //
//===================//
 
const int MX = 1e6+10;
const int N = (1<<20);

int n, m, q, k;
string s, t, w, W;
set<char> dif[101];
int mustHave;

bool canStartAt(int x) {
    RE(i,m-1) {
        int y = (x+1+i)%m;
        if(dif[y].empty()) continue;
        if(dif[y].size() != 1) return 0;
        if(*dif[y].begin() != s[i]) return 0;
    }
    return 1;
}
void getStringStartingAt(int x) {
    int i=x;
    W.clear();
    while(i < w.size()) {
        W.push_back(w[i]);
        i += m;
    }
}

int dp[MX];
void fillDP() {
    REV(i,0,W.size()) {
        RE(j,100) {
            int x=i+(1<<j);
            if(x >= W.size()) {
                dp[i] = j;
                break;
            }
            if(dp[x] <= j && W[x]==W[i]) {
                dp[i] = j;
                break;
            }
        }
    }
}

int canBeCenter(int x) {
    RE(i,100) {
        int y = x+(1<<i);
        y = y%(1<<(i+1));
        if(y >= W.size()) {
            return i;
        }
        if(i > k) return -1;
        if(W[y] != t[i]) return -1;
        if(dp[y] > i+1) return -1;
    }
    return -1;
}

const int MXN=1e5+10;
int cntT[MXN][26];
mi sumMod[MXN][26];

void program() {
    IN(n,q,s,t);
    FOR(c,s) c-='a';
    FOR(c,t) c-='a';

    m = s.size()+1;

    // fill cntT
    RE(i,26) cntT[0][i] = 0;
    RE(i,n) RE(j,26) cntT[i+1][j] = cntT[i][j] + (t[i] == j ? 1 : 0);
    
    // fill sum mod
    RE(i,n) sumMod[i+1][t[i]] += modpow(2,n-i-1);
    RE(i,n) RE(j,26) sumMod[i+1][j] += sumMod[i][j];
    
    RE(i,q) {
        IN(k,w); FOR(c,w) c-='a';

        RE(j,m) dif[j].clear();
        RE(j,w.size()) {
            dif[j%m].insert(w[j]);
        }

        mi res = 0;

        RE(j,m) {
            if(!canStartAt(j)) continue;
            getStringStartingAt(j);
            if(W.empty()) break;

            mustHave = 0;
            RE1(j,21) {
                if((1<<(j))<=W.size()) {
                    mustHave = j;
                } else {
                    break;
                }
            }

            fillDP();
            RE(i,W.size()) {
                int x = canBeCenter(i);
                if(x == -1) continue;
                res += sumMod[k][W[i]]-sumMod[min(k,x)][W[i]];
            }
        }
        
        res = res/mi(modpow(2,n-k));

        int cnt = 0;
        if(w.size() <= s.size()) {
            RE(i,s.size()-w.size()+1) {
                bool found = 1;
                RE(j,w.size()) {
                    if(s[i+j] != w[j]) {
                        found = 0;
                        break;
                    }
                }
                if(found) cnt++;
            }
        }

        res += mi(modpow(2,k))*mi(cnt);

        OUTL((ll)res);
    }
}