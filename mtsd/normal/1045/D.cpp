#include <bits/stdc++.h>
#define ll long long
#define INF 1000000005
#define MOD 1000000007
#define EPS 1e-10
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rrep(i,n) for(int i=(int)(n)-1;i>=0;--i)
#define srep(i,s,t) for(int i=(int)(s);i<(int)(t);++i)
#define each(a,b) for(const auto& (a): (b))
#define all(v) (v).begin(),(v).end()
#define len(v) (int)(v).size()
#define zip(v) sort(all(v)),v.erase(unique(all(v)),v.end())
#define cmx(x,y) x=max(x,y)
#define cmn(x,y) x=min(x,y)
#define fi first
#define se second
#define pb push_back
#define show(x) cout<<#x<<" = "<<(x)<<endl
#define sar(a,n) {cout<<#a<<":";rep(pachico,n)cout<<" "<<a[pachico];cout<<endl;}

using namespace std;

template<typename S,typename T>auto&operator<<(ostream&o,pair<S,T>p){return o<<"{"<<p.fi<<","<<p.se<<"}";}
template<typename T>auto&operator<<(ostream&o,set<T>s){for(auto&e:s)o<<e<<" ";return o;}
template<typename S,typename T,typename U>
auto&operator<<(ostream&o,priority_queue<S,T,U>q){while(!q.empty())o<<q.top()<<" ",q.pop();return o;}
template<typename K,typename T>auto&operator<<(ostream&o,map<K,T>&m){for(auto&e:m)o<<e<<" ";return o;}
template<typename T>auto&operator<<(ostream&o,vector<T>v){for(auto&e:v)o<<e<<" ";return o;}
void ashow(){cout<<endl;}template<typename T,typename...A>void ashow(T t,A...a){cout<<t<<" ";ashow(a...);}
template<typename S,typename T,typename U>
struct TRI{S fi;T se;U th;TRI(){}TRI(S f,T s,U t):fi(f),se(s),th(t){}
bool operator<(const TRI&_)const{return(fi==_.fi)?((se==_.se)?(th<_.th):(se<_.se)):(fi<_.fi);}};
template<typename S,typename T,typename U>
auto&operator<<(ostream&o,TRI<S,T,U>&t){return o<<"{"<<t.fi<<","<<t.se<<","<<t.th<<"}";}

typedef pair<int, int> P;
typedef pair<ll,ll> pll;
typedef TRI<int, int, int> tri;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<double> vd;
typedef vector<P> vp;
typedef vector<string> vs;

const int MAX_N = 100005;

vector<int> G[MAX_N];
int par[MAX_N];
double p[MAX_N], sm[MAX_N];

double dfs(int u, int pp){
    par[u] = pp;
    for(const int v : G[u]){
        if(v != pp) sm[u] += dfs(v, u);
    }
    return p[u];
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m, u, v, t;
    cin >> n;
    double a = 0, b = 0, diff;
    rep(i,n){
        cin >> p[i];
        a += (p[i] = 1.0 - p[i]);
    }
    rep(i,n-1){
        cin >> u >> v;
        b += p[u] * p[v];
        G[u].pb(v), G[v].pb(u);
    }
    dfs(0, -1);
    cin >> m;
    rep(i,m){
        cin >> t >> diff;
        diff = 1.0 - diff, diff -= p[t];
        a += diff, p[t] += diff, b += diff * sm[t];
        if(par[t] >= 0) b += p[par[t]] * diff, sm[par[t]] += diff;
        printf("%.12lf\n", a - b);
    }
    return 0;
}