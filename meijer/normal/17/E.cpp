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

// mod library
ll MOD=51123987;

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
    mi(ll v=0) {value = v%MOD;}
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
 
const int MX = 2e6+5, MX2 = 2e6+5;

int n;

struct Node {
    vii nxt;
    int sufflink, len;
    int cnt=0;
} tree[MX];

string s;
int suf, num;
int start[MX2];

void initTree() {
    num = suf = 2;
    tree[1].len = -1; tree[1].sufflink = 1;
    tree[2].len =  0; tree[2].sufflink = 1;
}
void addLetter(int pos) {
    int cur = suf, curLen = 0;
    int letter = s[pos]-'a';

    while(1) {
        curLen = tree[cur].len;
        if(pos-1-curLen >= 0 && s[pos-1-curLen] == s[pos])
            break;
        cur = tree[cur].sufflink;
    }
    FOR(p,tree[cur].nxt) if(p.fi == letter) {
        suf = p.se;
        return;
    }

    suf = ++num;
    tree[num].len = tree[cur].len+2;
    tree[cur].nxt.pb({letter, num});
    tree[num].cnt = 1;

    if(tree[num].len == 1) {
        tree[num].sufflink = 2;
        return;
    }

    while(1) {
        cur = tree[cur].sufflink;
        curLen = tree[cur].len;
        if(pos-1-curLen >= 0 && s[pos-1-curLen] == s[pos]) {
            FOR(p,tree[cur].nxt) if(p.fi == letter) {
                tree[num].sufflink = p.se;
                tree[num].cnt += tree[p.se].cnt;
                return;
            }
        }
    }
}

void program() {
    IN(n,s);
    reverse(all(s));
    initTree();
    RE(i,n) {
        addLetter(i);
        start[i] = tree[suf].cnt;
    }
    reverse(start,start+n);

    mi ans = 0;
    ll sm = 0;
    reverse(all(s));
    initTree();
    RE(i,n) {
        addLetter(i);
        ans -= mi(start[i])*mi(sm);
        sm += tree[suf].cnt;
    }
    if((sm%2) == 0) ans += mi(sm/2ll)*mi(sm-1);
    else ans += mi(sm)*mi((sm-1)/2ll);

    OUTL(ll(ans));
}