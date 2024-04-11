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
 
const int MX = 5e5;

int n;
int pls[MX];
int seq[MX];
int mn[MX];

void program() {
    IN(n);
    int A = 0, B = 0, C = 0;
    stack<int> stck;
    RE(i,n*2) {
        char c; IN(c);
        if(c == '+') {
            stck.push(B++);
            pls[A++] = 1;
        } else {
            pls[A++] = 0;
            int x; IN(x); mn[C++] = x;
            if(stck.empty()) {
                OUTL("NO");
                return;
            }
            seq[stck.top()] = x;
            stck.pop();
        }
    }

    set<int> S;
    A = 0, B = 0;
    bool pos = 1;
    RE(i,n*2) {
        if(pls[i]) {
            S.insert(seq[A++]);
        } else {
            if(S.empty() || *S.begin() != mn[B]) {
                pos = 0;
                break;
            } else {
                S.erase(mn[B++]);
            }
        }
    }
    cout<<(pos ? "YES" : "NO")<<endl;
    if(pos) {
        RE(i,n) OUT(i==0?"":" ", seq[i]);
        OUTL();
    }
}