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

vector<vector<int>> adj;
int n;

int bfs(int start){
    queue<int> qu;
    qu.push(start);
    vector<int> dist(n+1,-1);
    dist[start] = 0;
    while(!qu.empty()){
        int cur = qu.front();
        qu.pop();
        FORRC(i,adj[cur]){
            dist[i] = dist[cur] + 1;
            qu.push(i);
        }
    }
    return *max_element(all(dist));
}

int dfs(int node, int depth){
    int maxdepth = depth;
    FORRC(i,adj[node])
        maxdepth = max(dfs(i,depth+1),maxdepth);
    return maxdepth;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    adj.resize(n+1);
    int tmp;
    vector<int> arr;
    FORE(i,1,n){
        cin >> tmp;
        if(tmp!=-1)
            adj[tmp].push_back(i);
        else
            arr.pb(i);

    }
    //vi groups(n+1);
    int ans = 0;
    FORRC(x,arr){
        //ans = max(ans,bfs(x));
        ans = max(ans,dfs(x,0));
    }
    cout << ans+1 << '\n';
}