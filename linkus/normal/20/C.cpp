#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define all(a) (a.begin()),(a.end())
#define ZERO(a) meset(a,0,sizeof(a))
#define FOR(x,val,to) for(int x=(val);x<int((to));x++)
#define FORE(x,val,to) for(auto x=(val);x<=(to);x++)
#define FORR(x,arr) for(auto &x: arr)
#define FORRC(x,arr) for(auto const &x: arr)
#define PRINT(arr) {copy((arr).begin(), (arr).end(), ostream_iterator<int>(cout, " "));cout<<'\n';}
#define REE(s_) {cout<<s_<<'\n';return 0;} //print s_ and terminate program
#define GETVEC(vec,amount) copy_n(istream_iterator<int>(cin),(n),back_inserter((vec)))
#define GET(arr) for(auto &i: (arr)) cin>>i
#define MEMSET_INF 127 //2139062143 (USE FOR MEMSET) - memset(arr,MEMSET_INF,size)
#define INF 2139062143 //for comparison
#define ULL_INF 18446744073709551614 //for comparison
#define f first
#define s second
#define wtf(x) cerr << #x << " is " << x << endl;
#define whatis wtf
#define alive cerr << "STH" << endl;
typedef std::pair<int,int> pi;
typedef std::vector<int> vi;
typedef std::vector<std::string> vs;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int> > vvi;
using namespace std;

template<class T> ostream& operator<<(ostream &os, vector<T> V) {
  os<<"[";for(auto const &vv:V)os<<vv<<","; os<<"]";
  return os;
}
template<class L, class R> ostream& operator<<(ostream &os, pair<L, R> P) {
  os<<"("<<P.first<<","<<P.second<<")";
  return os;
}

vector<vector<pi>> adj;

vi dijkstra(int start, int end, int n){
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
    pq.push({0,start});
    vector<long long> dist(n,2e16);
    dist[start] = 0;
    vector<int> parent(n,-1);
    parent[start] = 1e9;
    while(!pq.empty()){
        int v = pq.top().second; ll w = pq.top().first; pq.pop();
        if(dist[v] < w) continue;
        FORRC(i,adj[v]){
            ll cur_w = w + i.first;
            if(cur_w < dist[i.second]){
                parent[i.second] = v;
                dist[i.second] = cur_w;
                pq.push({cur_w, i.second});
            }
        }
    }
    return parent;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    string str;
    int ver, edg;
    cin >> ver >> edg;
    adj.resize(ver+1);
    int a1,a2,a3;
    while(edg--){
        cin >> a1 >> a2 >> a3;
        adj[a1].pb({a3,a2});
        adj[a2].pb({a3,a1});
    }
    int a,b;
    auto ret = dijkstra(1,ver,ver+1);
    if(ret[ver] == -1)
        REE(-1);
    vi path;
    path.pb(ver);
    path.pb(ret[ver]);
    int cur = ret[path.back()];
    while(cur!=1e9){
        path.pb(cur);
        cur = ret[path.back()];
    }
    for(auto i = path.rbegin();i!=path.rend();++i)
        cout << *i << ' ';
    //ret == INF ? cout << "-1\n" : cout << ret << '\n';
}