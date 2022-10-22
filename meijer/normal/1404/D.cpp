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

const int MX = 1e6;

int n;
int p[MX];
int m[MX];
int q[MX][2];
int pos[MX];
vi chosen;

ll ans = 0;

void choose(int x) {
    chosen.pb(x);
    ans += x;
    pos[x] = 0;
    if(q[p[x]][0] == x) swap(q[p[x]][0], q[p[x]][1]);
    pos[q[p[x]][0]] = 0;
    int y = (x > n ? x-n : x+n);
    pos[y] = 0;

    if(q[p[y]][0] == y) swap(q[p[y]][0], q[p[y]][1]);
    if(pos[q[p[y]][0]]) choose(q[p[y]][0]);

}

void program() {
    IN(n);
    if((n%2) == 0) {
        OUTL("First");
        RE(i,n*2) OUT(i==0?"":" ", (i%n)+1); OUTL();
        cout.flush();
    } else {
        OUTL("Second");
        cout.flush();
        RE1(i,n*2) IN(p[i]);
        RE1(i,n*2) pos[i] = 1;
        RE1(i,n) m[i] = 0;
        RE1(i,n*2) q[p[i]][m[p[i]]++] = i;

        RE1(i,n*2) if(pos[i]) choose(i);
        if((ans % (n*2)) == 0) {
            sort(all(chosen));
        } else {
            RE1(i,n*2) pos[i] = 1;
            FOR(i,chosen) pos[i] = 0;
            chosen.clear();
            RE1(i,n*2) if(pos[i]) chosen.pb(i);
        }
        bool f=1;
        FOR(i,chosen) OUT(f?"":" ",i), f=0; OUTL();
        cout.flush();
    }
}