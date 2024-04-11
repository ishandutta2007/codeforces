#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
#include <queue>
#include <set>
#include <map>
#include <deque>
#include <iomanip>
#include <cstdio>
#include <stack>
#include <numeric>

using namespace std;
typedef  long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
#define  MP make_pair
#define  PB push_back
#define inf 1000000007
#define mod 1000000007
#define rep(i,n) for(int i=0;i<(int)(n);++i)

class UnionFind {
private:
    int sz;
    vector<int> par, nrank;
public:
    UnionFind(){}
    UnionFind(int node_size) : sz(node_size), par(sz), nrank(sz, 0){
        iota(par.begin(), par.end(), 0);
    }
    int find(int x){
        if(par[x] == x) return x;
        else return par[x] = find(par[x]);
    }
    void unite(int x,int y){
        x = find(x), y = find(y);
        if(x == y) return;
    	if(nrank[x] < nrank[y]) swap(x,y);
        par[y] = x;
        if(nrank[x] == nrank[y]) nrank[x]++;
    }
    bool same(int x,int y){
        return find(x) == find(y);
    }
};

int main(){
    int n,m;
    cin >> n >> m;
    UnionFind uf(n+1);
    vector<pair<int,pair<int,int> > > v;
    int s,t;
    rep(i,m){
        int a,b,c;
        cin >> a >> b >> c;
        if(i==0){
            s = a;
            t = b;
        }else{
            v.push_back(MP(c,MP(a,b)));
        }
    }
    sort(v.begin(),v.end());
    int res=1000000000;
    rep(i,m-1){
        int a,b;
        a = v[i].second.first;
        b = v[i].second.second;
        uf.unite(a,b);
        if(uf.same(s,t)){
            res = v[i].first;
            break;
        }
    }
    cout << res << endl;
    return 0;
}