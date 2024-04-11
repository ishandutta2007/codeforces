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
 
const int MX = 300, MX2 = 1e6;

int n, m;
string gr[MX];
int dif[MX];
ll sum[MX];
ll hsh[MX];
map<int, char> mp;

struct Node {
    vii nxt;
    int sufflink, len;
    int cnt=0;
} tree[MX2];

vi s;
int suf, num;

void initTree() {
    num = suf = 2;
    tree[1].len = -1; tree[1].sufflink = 1;
    tree[2].len =  0; tree[2].sufflink = 1;
    RE1(i,2) tree[i].nxt.clear();
}
int addLetter(int pos) {
    int cur = suf, curLen = 0;
    int letter = s[pos];

    while(1) {
        curLen = tree[cur].len;
        if(pos-1-curLen >= 0 && s[pos-1-curLen] == s[pos])
            break;
        cur = tree[cur].sufflink;
    }
    FOR(p,tree[cur].nxt) if(p.fi == letter) {
        suf = p.se;
        return tree[suf].cnt;
    }

    suf = ++num;
    tree[num].nxt.clear();
    tree[num].cnt = 1;
    tree[num].len = tree[cur].len+2;
    tree[cur].nxt.pb({letter,suf});

    if(tree[num].len == 1) {
        tree[num].sufflink = 2;
        return tree[suf].cnt;;
    }

    while(1) {
        cur = tree[cur].sufflink;
        curLen = tree[cur].len;
        if(pos-1-curLen >= 0 && s[pos-1-curLen] == s[pos]) {
            FOR(p,tree[cur].nxt) if(p.fi == letter) {
                tree[num].sufflink = p.se;
                tree[num].cnt += tree[tree[num].sufflink].cnt;
                return tree[suf].cnt;;
            }
        }
    }
}

int countPalin() {
    initTree();
    int res = 0;
    RE(i,s.size()) res += addLetter(i);
    return res;
}

void program() {
    IN(n,m);
    RE(i,n) IN(gr[i]);
    RE(i,n) RE(j,m) gr[i][j]-='a';

    RE(i,26) mp[1<<i] = 1;
    RE(i,26) hsh[i] = rng();
    mp[0] = 1;

    ll ans = 0;
    RE(j1,m) {
        RE(i,n) dif[i] = sum[i] = 0;
        REP(j2,j1,m) {
            RE(i,n) {
                dif[i] ^= (1<<gr[i][j2]);
                sum[i] += hsh[gr[i][j2]];
                auto it = mp.find(dif[i]);
                if(it == mp.end()) {
                    ans += countPalin();
                    s.clear();
                } else {
                    s.pb(sum[i]);
                }
            }
            ans += countPalin();
            s.clear();
        }
    }
    OUTL(ans);
}