#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define Fit(i,c) for (__typeof__((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define inf 1000000005
#define all(a) (a).begin(), (a).end()
#define ms(a,x) memset(a, x, sizeof(a))
#define mod 1000000007
#define sz(a) ((int)(a).size())
 
template<class T> int getbit(T s, int i) { return (s >> i) & 1; }
template<class T> T onbit(T s, int i) { return s | (T(1) << i); }
template<class T> T offbit(T s, int i) { return s & (~(T(1) << i)); }
template<class T> int cntbit(T s) { return __builtin_popcount(s);}
 
#define Rep(i,n) for(int i = 0; i < (n); ++i)
#define Repd(i,n) for(int i = (n)-1; i >= 0; --i)
#define For(i,a,b) for(int i = (a); i <= (b); ++i)
#define Ford(i,a,b) for(int i = (a); i >= (b); --i)
 
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
#define eps 1e-9
typedef pair<int, int> II;
template<class T> T gcd(T a, T b){ T r; while (b != 0) { r = a % b; a = b; b = r; } return a;}
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
 
#define maxn 400005
 
int n, m;
 
struct edge{
    int from, to, cost;
    edge(){};
    edge(int _from, int _to, int _cost){
        from = _from;
        to = _to;
        cost = _cost;
    }
 
    bool operator <(const edge &E) const{
        return cost < E.cost;
    }
};
 
edge E[maxn];
int f[maxn];
 
int main(){
 
//  freopen("in.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cin >> n >> m;
    int u, v, c;
    Rep(run, m){
        cin >> u >> v >> c;
        E[run] = edge(u, v, c);
    }
 
    sort(E, E + m);
    ms(f, 0);
 
    vector<II> V;
    int res = 0;
    Rep(i, m){
        u = E[i].from; v = E[i].to; c = E[i].cost;
//      cout << u << " " << v << " " << c << " " << f[u] << endl;
 
        if(i && c > E[i - 1].cost){
//          if(sz(V)) cout << V[0].fi << " " << V[0].se << endl;
            Rep(j, sz(V)){
                f[V[j].fi] = max(f[V[j].fi], V[j].se);
            }
            V.clear();
        }
 
        res = max(res, f[u] + 1);
        V.push_back(mp(v, f[u] + 1));
    }
 
    cout << res << endl;
 
    return 0;
}