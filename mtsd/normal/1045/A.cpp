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

const int MAX_N = 5005;

set<int> bas;
int kind[2 * MAX_N], lef[2 * MAX_N], rig[2 * MAX_N];
bool used[3 * MAX_N];

class BM {
private:
    const int U, V;
    vector<vector<int> > G;
    vector<int> ralloc;
    set<int> st;
    bool dfs(const int u){
        used[u] = true;
        if(u >= U){
            st.erase(u - U);
            if(ralloc[u - U] < 0) return true;
            else return dfs(ralloc[u - U]);
        }else{
            if(kind[u] == 1){
                while(!st.empty()){
                    auto it = st.lower_bound(lef[u]);
                    if(it == st.end() || *it >= rig[u]) break;
                    const int v = *it + U;
                    if(dfs(v)){
                        alloc[u] = v - U, ralloc[v - U] = u;
                        return true;
                    }
                }
            }else{
                for(const int v : G[u]){
                    if(!used[v] && dfs(v)){
                        alloc[u] = v - U, ralloc[v - U] = u;
                        return true;
                    }
                }
            }
        }
        return false;
    }
public:
    BM(const int u, const int v)
         : U(u), V(v), G(U + V), ralloc(V, -1), alloc(U, -1){}
    void add_edge(const int from, const int to){
        G[from].push_back(U + to);
    }
    // alloc 
    vector<int> alloc;
    int solve(){
        int flow = 0;
        while(true){
            memset(used, 0, sizeof(used));
            bool update = false;
            st = bas;
            for(int i = 0; i < U; ++i){
                if(alloc[i] < 0 && dfs(i)){
                    ++flow, update = true;
                    break;
                }
            }
            if(!update) break;
        }
        return flow;
    }
};

vector<int> kep[2 * MAX_N];
int a[2 * MAX_N], b[2 * MAX_N], c[2 * MAX_N], d[MAX_N];
bool dame[MAX_N];

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m, t, K, x;
    cin >> n >> m;
    rep(i,m) bas.insert(i);
    int num = n;
    rep(i,n){
        cin >> t;
        kind[i] = t;
        if(t == 0){
            cin >> K;
            rep(j,K){
                cin >> x;
                --x;
                kep[i].pb(x);
            }
        }else if(t == 1){
            cin >> lef[i] >> rig[i];
            --lef[i];
        }else{
            cin >> a[i] >> b[i] >> c[i];
            --a[i], --b[i], --c[i];
            a[num] = a[i], b[num] = b[i], c[num] = c[i];
            kind[num] = 2, d[i] = num, ++num;
        }
    }
    BM bm(num, m);
    rep(i,num){
        if(kind[i] == 0){
            for(const int e : kep[i]){
                bm.add_edge(i, e);
            }
        }else if(kind[i] == 2){
            if(a[i] == b[i] && b[i] == c[i]) continue;
            bm.add_edge(i, a[i]);
            bm.add_edge(i, b[i]);
            bm.add_edge(i, c[i]);
        }
    }
    cout << bm.solve() << "\n";
    const auto& alloc = bm.alloc;
    rep(i,n){
        if(kind[i] == 2){
            if(alloc[i] < 0 && alloc[d[i]] >= 0){
                if(a[i] != alloc[d[i]]){
                    dame[a[i]] = true;
                    cout << i + 1 << " " << a[i] + 1 << "\n";
                }else if(b[i] != alloc[d[i]]){
                    dame[b[i]] = true;
                    cout << i + 1 << " " << b[i] + 1 << "\n";
                }else{
                    dame[c[i]] = true;
                    cout << i + 1 << " " << c[i] + 1 << "\n";
                }
                cout << i + 1 << " " << alloc[d[i]] + 1 << "\n";
            }else if(alloc[i] >= 0 && alloc[d[i]] < 0){
                if(a[i] != alloc[i]){
                    dame[a[i]] = true;
                    cout << i + 1 << " " << a[i] + 1 << "\n";
                }else if(b[i] != alloc[i]){
                    dame[b[i]] = true;
                    cout << i + 1 << " " << b[i] + 1 << "\n";
                }else{
                    dame[c[i]] = true;
                    cout << i + 1 << " " << c[i] + 1 << "\n";
                }
                cout << i + 1 << " " << alloc[i] + 1 << "\n";
            }else if(alloc[i] >= 0 && alloc[d[i]] >= 0){
                cout << i + 1 << " " << alloc[i] + 1 << "\n";
                cout << i + 1 << " " << alloc[d[i]] + 1 << "\n";
            }
        }
    }
    rep(i,n){
        if(kind[i] != 2 && alloc[i] >= 0 && !dame[alloc[i]]){
            cout<< i + 1 << " " << alloc[i] + 1 << "\n";
        }
    }
    return 0;
}