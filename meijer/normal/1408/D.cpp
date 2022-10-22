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
 
const int MX = 1e6+10;

int n, m, a[MX], b[MX], c[MX], d[MX];
int A[MX], B[MX], C[MX], D[MX];
int SA[MX];
vi comp;
int highB[2001];
stack<int> dif[2001];

void program() {
    IN(n,m);
    RE(i,n) IN(A[i],B[i]);
    RE(i,m) IN(C[i],D[i]);

    RE(i,n) SA[i]=i;
    sort(SA,SA+n,[](int i, int j) {
        return A[i]>A[j];
    });
    int nn=0, lastb=-1;
    RE(i,n) {
        if(B[SA[i]] > lastb) {
            a[nn] = A[SA[i]];
            b[nn] = B[SA[i]];
            lastb = B[SA[i]];
            nn++;
        }
    }
    n = nn;
    RE(i,n) comp.pb(a[i]);
    sort(all(comp));
    RE(i,n) a[i] = lower_bound(all(comp),a[i])-comp.begin();

    RE(i,m) SA[i]=i;
    sort(SA,SA+m,[](int i, int j) {
        return C[i]>C[j];
    });
    int mm=0, lastd=-1;
    RE(i,m) {
        if(D[SA[i]] > lastd) {
            c[mm] = C[SA[i]];
            d[mm] = D[SA[i]];
            lastd = D[SA[i]];
            mm++;
        }
    }
    m = mm;

    RE(i,n) highB[i]=INF;
    RE(i,n) highB[a[i]] = min(highB[a[i]], b[i]);

    viii pq;
    RE(i,n) RE(j,m) {
        int time = c[j]-comp[a[i]];
        if(time < 0) continue;
        dif[a[i]].push(d[j]);
        pq.pb({time,i,j});
    }
    sort(all(pq));

    multiset<int> curAns;
    RE(i,n) {
        if(highB[i] == INF) continue;
        if(!dif[i].empty())
            curAns.insert(max(0,dif[i].top()-highB[i]+1));
    }

    int ans = (curAns.empty() ? 0 : *(--curAns.end()));
    FOR(p,pq) {
        int t,I,J;
        tie(t,I,J) = p;
        int x = a[I];
        curAns.erase(curAns.find(max(0,dif[x].top()-highB[x]+1)));
        dif[x].pop();
        if(!dif[x].empty())
            curAns.insert(max(0,dif[x].top()-highB[x]+1));
        if(!curAns.empty())
            ans = min(ans, *(--curAns.end())+t+1);
        else ans = min(ans,t+1);
    }
    OUTL(ans);
}