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
int n,m;

bool ok(int i,int j){
    if(i<0||i>=n)return false;
    if(j<0||j>=m)return false;
    return true;
}
class UnionFind {
private:
    int sz;
    vector<int> par, size_;
public:
    UnionFind(){}
    UnionFind(int node_size) : sz(node_size), par(sz), size_(sz, 1){
        iota(par.begin(), par.end(), 0);
    }
    int find(int x){
        if(par[x] == x) return x;
        else return par[x] = find(par[x]);
    }
    void unite(int x,int y){
        x = find(x), y = find(y);
        if(x == y) return;
        if(size_[x] < size_[y]) swap(x,y);
        par[y] = x;
        size_[x] += size_[y];
    }
    int size(int x){
        x = find(x);
        return size_[x];
    }
    bool same(int x,int y){
        return find(x) == find(y);
    }
};


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    vector<string>s(n);
    vector<vector<int> >d(n,vector<int>(m));
    rep(i,n)cin >> s[i];
    vector<vector<bool>> flag(n,vector<bool>(m));
    queue<pair<pair<int,int>,int> > q;
    UnionFind uf(n*m);
    rep(i,n){
        q.push(MP(MP(i,-1),0));
        q.push(MP(MP(i,m),0));
    }
    rep(j,m){
        q.push(MP(MP(-1,j),0));
        q.push(MP(MP(n,j),0));
    }
    rep(i,n){
        rep(j,m){
            if(s[i][j]=='.'){
                flag[i][j] = true; 
                q.push(MP(MP(i,j),0));
            }
        }
    }
    while(!q.empty()){
        auto x = q.front();
        q.pop();
        int i = x.first.first;
        int j = x.first.second;
        int t = x.second;
        if(ok(i,j))d[i][j] = t;
        for(int di=-1;di<=1;di++){
            for(int dj=-1;dj<=1;dj++){
                if(ok(i+di,j+dj)){
                    if(ok(i,j)&&(di==0||dj==0)&&s[i][j]=='X'&&s[i+di][j+dj]=='X'){
                        uf.unite(i*m+j,(i+di)*m+j+dj);
                    }
                    if(!flag[i+di][j+dj]){
                        flag[i+di][j+dj] = true;
                        q.push(MP(MP(i+di,j+dj),t+1));
                    }
                }
            }
        }
    }
    vector<int> res(n*m,-1);
    rep(i,n){
        rep(j,m){
            if(s[i][j]=='X'){
                int K = uf.find(i*m+j); 
                res[K] = max(d[i][j],res[K]);
            }
        }
    }
    int p = inf;
    rep(i,n*m){
        if(res[i]!=-1){
            p = min(res[i],p);
        }
    }
    //cout << p-1 << endl;
    int OK = 1;
    int NG = p+1;
    vector<string > t(n);
    while(NG-OK>1){
        int mid = (OK+NG)/2;
        string ppp;
        rep(j,m){
            ppp.push_back('.');
        }
        rep(i,n){
            t[i] = ppp;
        }
        rep(i,n){
            rep(j,m){
                if(s[i][j]=='X'&&d[i][j]>=mid){
                    t[i][j] = 'X';
                }else{
                    t[i][j] = '.';
                }
            }
        }
        rep(i,n){
            rep(j,m){
                flag[i][j] = false;
            }
        }
        rep(i,n){
            rep(j,m){
                if(t[i][j]=='X'){
                    flag[i][j] = true; 
                    q.push(MP(MP(i,j),1));
                }
            }
        }
        while(!q.empty()){
            auto x = q.front();
            q.pop();
            int i = x.first.first;
            int j = x.first.second;
            int tm = x.second;
            t[i][j] = 'X';
            if(tm==mid)continue;
            for(int di=-1;di<=1;di++){
                for(int dj=-1;dj<=1;dj++){
                    if(ok(i+di,j+dj)){
                        if(!flag[i+di][j+dj]){
                            flag[i+di][j+dj] = true;
                            q.push(MP(MP(i+di,j+dj),tm+1));
                        }
                    }
                }
            }
        }
        bool flag = 1;
        rep(i,n){
            if(s[i]!=t[i]){
                flag = 0;
                break;
            }
        }
        if(flag){
            OK = mid;
        }else{
            NG = mid;
        }
    }
    cout << OK-1 << endl;
    rep(i,n){
        rep(j,m){
            if(s[i][j]=='X'&&d[i][j]>=OK){
                cout << 'X';
            }else{
                cout << '.';
            }
        }
        cout << "\n";
    }
    // rep(i,n){
    //     rep(j,m){
    //         if(s[i][j]=='X'){
    //             cout << uf.find(i*m+j);
    //         }else{
    //             cout << '.';
    //         }
    //     }
    //     cout << "\n";
    // }
    return 0;
}