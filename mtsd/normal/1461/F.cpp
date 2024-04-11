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
#include <iomanip>
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
typedef vector<int> vi;
typedef pair<int,int> pii;
#define MP make_pair
#define PB push_back
#define inf 1000000007
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()

template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}
 
template<class T> inline bool chmax(T &a, T b){
    if(a<b){
        a = b;
        return true;
    }
    return false;
}

template<class T> inline bool chmin(T &a, T b){
    if(a>b){
        a = b;
        return true;
    }
    return false;
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

bool p[3];
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    string s;
    cin >> s;
    rep(i,s.size()){
        if(s[i]=='+'){
            p[0] = 1;
        }
        if(s[i]=='-'){
            p[1] = 1;
        }
        if(s[i]=='*'){
            p[2] = 1;
        }
    }
    if(!p[2]){
        if(p[0]){
            rep(i,n){
                cout << a[i];
                if(i!=n-1)cout << "+";
            }
            cout << "\n";
        }else{
            rep(i,n){
                cout << a[i];
                if(i!=n-1)cout << "-";
            }
            cout << "\n";
        }
        return 0;
    }
    if(!p[0]){
        if(!p[1]){
            rep(i,n){
                cout << a[i];
                if(i!=n-1)cout << "*";
            }
            cout << "\n";
        }else{
            bool flag = 0;
            rep(i,n){
                cout << a[i];
                if(i+1<n&&a[i+1]==0){
                    if(!flag){
                        flag = 1;
                        cout << "-";
                    }else{
                        if(i!=n-1)cout << "*";
                    }
                }else{
                    if(i!=n-1){
                        cout << "*";
                    }
                }
            }
            cout << "\n";
        }
    }else{
        vector<char> res(n);
        vector<vector<pair<int,int> > > p;
        vector<pair<int,int> > tmp;
        int id = 0;
        while(id!=n){
            int k = 0;
            if(a[id]==1){
                while(id!=n&&a[id]==1){
                    id++;
                    k++;
                }
                tmp.push_back(MP(0,k));
            }else{
                if(a[id]==0){
                    p.push_back(tmp);
                    tmp.clear();
                    tmp.push_back(MP(3,0));
                    p.push_back(tmp);
                    tmp.clear();
                    id++;
                }else{
                    tmp.push_back(MP(1,a[id]));
                    id++;
                }
            }
        }
        p.push_back(tmp);
        id = 0;
        for(auto& x:p){
            if(x.size()==0)continue;
            if(x[0].first==3){
                res[id] = '+';
                id++;
                continue;
            }
            int m = x.size();
            // cerr << m << endl;
            // rep(i,m)cerr << x[i].first << " " << x[i].second << "\n";
            // cerr << "\n";
            int sm = 0;
            ll K = 1;
            bool fflag = 0;
            rep(i,m){
                if(x[i].first==0){
                    if(i!=0&&i!=m-1){
                        sm += x[i].second;
                    }
                }else{
                    K *= x[i].second;
                    if(K >= 3000000){
                        fflag = 1;
                        break;
                    }
                }
            }
            if(fflag || K >= 10*sm){
                rep(i,m){
                    if(x[i].first==0){
                        if(i==0||i==m-1){
                            rep(j,x[i].second){
                                res[id] = '+';
                                id++; 
                            }
                        }else{
                            rep(j,x[i].second){
                                res[id] = '*';
                                id++; 
                            }
                        }
                    }else{
                        res[id] = '*';
                        id++;
                        if(i==m-2&&x[i+1].first==0){
                            res[id-1] = '+';
                        }
                    }
                }
                res[id-1] = '+';
            }else{
                
                ll mx = 0;
                
                int mxbit = 0;
                rep(bit,1<<(m-1)){
                    UnionFind uf(m);
                    rep(i,m-1){
                        if((bit>>i)&1){
                            uf.unite(i,i+1);
                        }
                    }
                    ll S = 0;
                    ll tmp = 1;
                    bool flag = 1;
                    rep(i,m){
                        if(i==m-1||!uf.same(i,i+1)){
                            if(flag){
                                S += x[i].second;
                            }else{
                                if(x[i].first==0){
                                    
                                }else{
                                    tmp *= x[i].second;
                                }
                                S += tmp;
                            }
                            flag = 1;
                            tmp = 1;
                        }else{
                            flag = 0;
                            if(x[i].first==0){
                                
                            }else{
                                tmp *= x[i].second;
                            }
                        }
                    }
                    if(chmax(mx,S)){
                        mxbit = bit;
                    }
                }
                UnionFind uf(m);
                rep(i,m-1){
                    if((mxbit>>i)&1){
                        uf.unite(i,i+1);
                    }
                }
                bool flag = 0;
                rep(i,m){
                    if(i==m-1||!uf.same(i,i+1)){
                        if(x[i].first==0){
                            rep(j,x[i].second){
                                res[id] = '+';
                                id++;
                            }
                        }else{
                            res[id] = '+';
                            id++;
                        }
                        flag = 1;    
                    }else{
                        if(x[i].first==0){
                            rep(j,x[i].second){
                                res[id] = '*';
                                id++;
                            } 
                        }else{
                            res[id] = '*';
                            id++;
                        }
                        flag = 0;
                    }
                }
            }
            
        }
        rep(i,n){
            cout << a[i];
            if(i!=n-1)cout << res[i];
        }
        cout << "\n";
    }
    return 0;
}