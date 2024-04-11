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
#define EPS 1e-2
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

int testCases;
int n;
ld l, a[MX];

void program() {
    IN(testCases);
    cout<<setprecision(16);
    while(testCases--) {
        IN(n,l);
        RE(i,n) IN(a[i]);

        ld x1=0, x2=l;
        ld s1=1.0, s2=1.0;
        ld time = 0.0;
        ll curLeft = 0;
        ll curRight = n-1;
        while(x1 < x2) {
            ld meetTime = (x2-x1)/(s2+s1);
            ld x1Time=INF; 
            ld x2Time=INF; 
            if(curLeft < n) x1Time = (a[curLeft]-x1)/s1;
            if(curRight >= 0) x2Time = (x2-a[curRight])/s2;
            ld addedTime = min({meetTime, x1Time, x2Time});
            time += addedTime;
            x1 += s1*addedTime;
            x2 -= s2*addedTime;
            while(curLeft < n && x1+EPS >= a[curLeft]) {
                s1 += 1.0;
                curLeft++;
            }
            while(curRight >= 0 && x2 <= a[curRight]+EPS) {
                s2 += 1.0;
                curRight--;
            }
        }
        OUTL(time);
    }
}