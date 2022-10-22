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

const int MX = 5e5;

ll n;
map<ll, ll> T;
set<ll> nd;
set<ll> db;
set<ll> allT;
ll maxDB=0;

void program() {
    IN(n);
    ll ans = 0;
    RE(i,n) {
        ll t, d;
        IN(t,d);
        if(d < 0) {
            d = -d;
            ans -= d;
            if(t == 1) maxDB--, allT.erase(d);
            nd.erase(d);
            if(db.count(d)) {
                db.erase(d);
                ans -= d;
            }
        } else {
            T[d] = t;
            ans += d;
            if(t == 1) maxDB++, allT.insert(d);
            nd.insert(d);
        }
        ll ndb;
        if(!allT.empty()) {
            ndb = *allT.begin();
            if(db.count(ndb)) {
                ans -= ndb;
                nd.insert(ndb);
                db.erase(ndb);
            }
        }
        while(db.sz > maxDB) {
            ans -= *db.begin();
            nd.insert(*db.begin());
            db.erase(db.begin());
        }
        while(db.sz < maxDB) {
            auto it = nd.end();
            bool c = 0;
            while(it != nd.begin()) {
                it--;
                if(*it != ndb) {
                    c = 1;
                    ans += *it;
                    nd.erase(it);
                    db.insert(*it);
                    break;
                }
            }
            if(!c) break;
        }
        while(1) {
            if(!nd.sz) break;
            if(!db.sz) break;
            auto it = nd.end();
            if(it == nd.begin()) break;
            it--;
            if(*it == ndb) {
                if(it == nd.begin()) break;
                it--;
            }
            if(*it > *db.begin()) {
                ll a = *it;
                ll r = *db.begin();
                nd.erase(a);
                db.insert(a);
                nd.insert(r);
                db.erase(r);
                ans -= r;
                ans += a;
            } else {
                break;
            }
        }
        OUTL(ans);
    }
}