#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <climits>
#include <cmath>
#include <complex>
#include <cstring>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <cstdint>
using namespace std;
typedef long long ll;
#define MP make_pair
#define PB push_back
#define inf 1000000007
#define mod 1000000007
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
int n;
vector<vector<int> > g;
vector<int> c;
vector<int> res;
vector<int> sb;
vector<bool> used;
int dfs(int id,int pre){
    int sm = 0;
    for(auto x:g[id]){
        if(x==pre)continue;
        sm += dfs(x,id);
    }
    sb[id] = sm;
    sm++;
    return sm;
}

void dfs2(int id,int pre,int val){
    int tar = c[id]+1;
    int cc = 0;
    for(int i=val;i<=n;i++){
        if(!used[i])cc++;
        if(tar==cc){
            res[id] = i;
            used[i] = 1;
            break;
        }
    }
    int s = val;
    for(auto x:g[id]){
        if(x==pre)continue;
        
        tar = sb[x] + 1;
        int kk = 0;
        for(int i=s;i<=n;i++){
            if(!used[i])kk++; 
            if(tar==kk){
                dfs2(x,id,s);
                s = i+1;
                break;
            }
        }
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    g.resize(n);
    c.resize(n);
    res.resize(n);
    sb.resize(n);
    used.resize(n+1);
    int r = 0;
    rep(i,n){
        int a,b;
        cin >> a >> b;
        a--;
        if(a==-1){
            r = i;
        }else{
            g[i].push_back(a);
            g[a].push_back(i);
        }
        c[i] = b;
    }
    dfs(r,-1);
    rep(i,n){
        if(c[i] > sb[i]){
            cout << "NO" << endl;
            return 0;
        }
    }
    dfs2(r,-1,1);
    cout << "YES" << endl;
    for(int i=0;i<n;i++){
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}