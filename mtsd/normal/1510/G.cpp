#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
typedef long long ll;

template<class T> inline bool chmax(T &a, T b){
    if(a<b){
        a = b;
        return true;
    }
    return false;
}

vector<vector<int> > g;
vector<int> dep;
vector<int> res;

int n,k;
void init(int id,int pre){
    int mx = 0;
    for(auto x:g[id]){
        if(x==pre)continue;
        init(x,id);
        chmax(mx,dep[x]);
    }
    mx++;
    dep[id] = mx;
}

void ddd(int id,int pre){
    if(k==0)return;
    k--;
    res.push_back(id);
    int nxt = -1;
    for(auto x:g[id]){
        if(x==pre)continue;
        if(dep[x] == dep[id]-1){
            nxt = x;
            break;
        }
    }
    ddd(nxt,id);
}
void dfs2(int id,int pre){
    res.push_back(id);
    k--;
    for(auto x:g[id]){
        if(x==pre)continue;
        if(k!=0){
            dfs2(x,id);
            res.push_back(id);
        }
    }
}
void dfs(int id,int pre){
    res.push_back(id);
    int nxt = -1;
    for(auto x:g[id]){
        if(x==pre)continue;
        if(dep[x] == dep[id]-1){
            nxt = x;
            break;
        }
    }
    if(nxt==-1)return;
    if(k==0){
        dfs(nxt,id);
    }else{
        for(auto x:g[id]){
            if(k==0)break;
            if(x==nxt||x==pre)continue;
            dfs2(x,id);
            res.push_back(id);
        }
        dfs(nxt,id);
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    rep(zz,t){
        cin >> n >> k;
        g.resize(n);
        dep.resize(n);
        vector<int> p(n);
        rep(i,n-1){
            cin >> p[i];
            p[i]--;
            g[i+1].push_back(p[i]);
            g[p[i]].push_back(i+1);
        }
        init(0,-1);
        if(dep[0] >= k){
            ddd(0,-1);
        }else{
            k -= dep[0];
            dfs(0,-1);   
        }
        cout << (int)res.size() -1 << "\n";
        rep(i,res.size()){
            cout << res[i]+1;
            if(i!=(int)res.size()-1) cout << " ";
        }
        cout << "\n";
        dep.clear();
        res.clear();
        g.clear();
    }

    return 0;
}