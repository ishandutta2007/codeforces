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

const int MX = 1e6+2;

int n;
string s;
int maxR[MX][2];
int ans[MX];

int SEG[MX*2];
void setSeg(int i, int v) {
    for(SEG[i+=n]=v; i>1; i/=2) SEG[i/2] = min(SEG[i], SEG[i^1]);
}
int getSeg(int l, int r) {
    int ans = INF;
    for(l+=n, r+=n; l<r; l/=2, r/=2) {
        if(l&1) ans = min(ans, SEG[l++]);
        if(r&1) ans = min(ans, SEG[--r]);
    }
    return ans;
}

void program() {
    IN(n,s); s.pb('2');
    maxR[n][0] = 0;
    maxR[n][1] = 0;
    REV(i,0,n) {
        RE(j,2) {
            if(s[i] == '?') maxR[i][j] = maxR[i+1][j]+1;
            else maxR[i][j] = (s[i] == '0'+j ? maxR[i+1][j]+1 : 0);
        }
    }
    RE(i,n*2) SEG[i] = INF;
    priority_queue<ii> pq;
    RE(i,n) pq.push({max(maxR[i][0],maxR[i][1]),i});
    REV(i,1,n+1) {
        while(!pq.empty() && pq.top().fi >= i) {
            ii p = pq.top(); pq.pop();
            setSeg(p.se, p.se);
        }
        int res = 0;
        int x = getSeg(0,n);
        while(x < INF) {
            res++;
            x = getSeg(x+i,n);
        }
        ans[i-1] = res;
    }
    RE(i,n) OUT(i==0?"":" ",ans[i]); OUTL();
}