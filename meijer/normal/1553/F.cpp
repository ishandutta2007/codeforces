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
 
const int MX = 1e6;
const int N = (1<<20);
const int SQ = 550;

ll n, a[MX];
ll p[MX];

ll CNT[MX];
void addCNT(int i, ll value) {
    for(i++; i<MX; i+=i&-i) CNT[i] += value;
}
ll getCNT(int i) {
    ll ans = 0;
    for(i++; i; i-=i&-i) ans += CNT[i];
    return ans;
}
ll SUM[MX];
void addSUM(int i, ll value) {
    for(i++; i<MX; i+=i&-i) SUM[i] += value;
}
ll getSUM(int i) {
    ll ans = 0;
    for(i++; i; i-=i&-i) ans += SUM[i];
    return ans;
}

ll cnt[MX];

void program() {
    IN(n);
    RE(i,n) IN(a[i]);
    
    p[0] = 0;
    addCNT(a[0],1);
    addSUM(a[0],a[0]);
    cnt[a[0]]++;
    REP(i,1,n) {
        p[i] = p[i-1];

        {
            ll j = 0;
            while(true) {
                int lb = j*a[i];
                int ub = (j+1)*a[i] - 1;
                if(ub >= MX)
                    break;
                p[i] += getSUM(ub) - getSUM(lb-1) - j*(getCNT(ub) - getCNT(lb-1))*a[i];
                j++;
            }
        }

        {
            ll j = 0;
            ll ub = 3e5+10;
            REP(k,1,SQ) {
                if(cnt[k]) {
                    p[i] += a[i]%k;
                }
            }
            while(true) {
                ll lb = a[i]/(j+1)+1;
                lb = max<ll>(lb,SQ);
                if(lb <= ub)
                    p[i] += (getCNT(ub) - getCNT(lb-1))*a[i] - j*(getSUM(ub) - getSUM(lb-1));
                lb = a[i]/(j+1)+1;
                if(lb < SQ)
                    break;
                lb = max<ll>(lb,SQ);
                j++;
                ub = lb-1;
            }
        }

        addCNT(a[i],1);
        addSUM(a[i],a[i]);
        cnt[a[i]]++;
    }

    RE(i,n) OUT(p[i],(i==n-1?"":" "));
    OUTL();
}