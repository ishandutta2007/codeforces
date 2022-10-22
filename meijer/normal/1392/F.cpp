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

const int MX = 1e6+1e5;

ll n, h[MX];
stack<ll> same;

ll FT[MX];
void addFT(ll i, ll value) {
    for(i++; i<=n; i+=i&-i) FT[i] += value;
}
ll getFT(ll i) {
    ll ans = 0;
    for(i++; i; i-=i&-i) ans += FT[i];
    return ans;
}

void program() {
    IN(n);
    RE(i,n) IN(h[i]);
    RE(i,n+1) FT[i] = 0;
    addFT(0,h[0]);
    same.push(0);
    REP(i,1,n) {
        while(getFT(i-1)+2 <= h[i]) {
            ll x = same.top();
            ll rem = h[i] - getFT(i-1) - 1;
            ll y = min(x+rem,(ll)i);
            rem = y-x;

            ll amount = 1;
            if(y == i && x == 0) {
                ll lb=1,ub=ll(h[i] - getFT(i-1) + rem+1ll)/rem;
                while(lb < ub) {
                    ll mid=(lb+ub+1)/2ll;
                    ll nh = h[i] - rem*mid;
                    ll nl = getFT(i-1) + mid;
                    if(nl+1 <= nh) lb = mid;
                    else ub = mid-1;
                }
                amount = lb;
            }
            h[i] -= rem*amount;
            addFT(x, amount);
            addFT(y,-amount);
            if(x != 0) same.pop();
            if(y != i) same.push(y);
        }
        if(getFT(i-1) == h[i]) {
            same.push(i);
        }
        addFT(i,h[i]-getFT(i));
    }
    RE(i,n) OUT(i==0?"":" ",getFT(i)); OUTL();
}