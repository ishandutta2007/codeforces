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
int n,m;
vector<vector<pair<int,ll > > > g;
int s,t;
bool ffff = 0;
bool flag[1001];
void dfs1(int id,int pre,vector<pair<pair<int,int>,ll> > &res,vector<vector<pair<int,ll > > > &p){
    if(id==s){
        rep(i,n)flag[i] = 0;
        ffff = 0;
    }
    flag[id] = 1;
    if(id==t){
        ffff = 1;
        return;
    }
    for(auto x:p[id]){
        if(x.first==pre)continue;
        if(!flag[x.first])dfs1(x.first,id,res,p);
        if(ffff){
            res.push_back(MP(MP(id,x.first),x.second));
            return;
        }
    }
}
int dep[10001];
void dfs2(int id,int pre,ll w,vector<int>&imos,vector<vector<pair<int,ll > > > &p){
    if(id==s){
        rep(i,n)flag[i] = 0;
        rep(i,n)dep[i] = 0;
        ffff = 0;
    }else{
        dep[id] = dep[pre] + 1;
    }
    flag[id] = 1;
    
    bool fff = 0;
    for(auto x:p[id]){
       
        if(flag[x.first]){
            // cerr << id << " " << x.first << "::" << endl;
            if(fff){
                if(dep[x.first]<dep[id]){
                    // cerr << "test\n";    
                    imos[x.first] += -1;
                    imos[id] += 1;
                }
            }else{
                if(x.first == pre && x.second ==w)fff = 1;
                else{
                    if(dep[x.first]<dep[id]){    
                        // cerr << "test\n";
                        imos[x.first] += -1;
                        imos[id] += 1;
                    }
                }
            }
        }else{
            dfs2(x.first,id,x.second,imos,p);
            imos[id] += imos[x.first];
        }
    }
}


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    vector<pair<pair<int,int>,ll> >edge;
    cin >> s >> t;
    s--;t--;
    g.resize(n);
    rep(i,m){
        int a,b;
        ll w;
        cin >> a >> b  >> w;
        a--;b--;
        edge.push_back(MP(MP(a,b),w));
        if(a!=b){
            g[a].push_back(MP(b,w));
            g[b].push_back(MP(a,w));
        }
    }   
    vector<pair<pair<int,int>,ll> > res;
    dfs1(s,-1,res,g);
    ll mi = (1LL<<60);
    vector<int> ans;
    if(res.size()==0){
        cout << 0 << endl;
        cout << 0 << endl;
        return 0;
    }
    for(auto x:res){
        // cerr << x.first.first << " " << x.first.second << endl;
        vector<vector<pair<int,ll > > > gg(n);
        vector<pair<pair<int,int>,ll> >e;
        bool ff = 0;
        int id = -1;
        rep(i,m){
            if(ff){
                e.push_back(edge[i]);
            }else{
                if(edge[i]==x||edge[i]==MP(MP(x.first.second,x.first.first),x.second)){
                    ff = 1;
                    id = i;
                }else{
                    e.push_back(edge[i]);
                }
            }
        }
        for(auto y:e){
            if(y.first.first!=y.first.second){
                gg[y.first.first].push_back(MP(y.first.second,y.second));
                gg[y.first.second].push_back(MP(y.first.first,y.second));
            }
        }
        vector<pair<pair<int,int>,ll> > res2;
        dfs1(s,-1,res2,gg);
        if(res2.size()==0){
            if(chmin(mi,x.second)){
                ans.clear();
                ans.push_back(id);
            }
            continue;
        }
        vector<int> imos(n);
        dfs2(s,-1,0,imos,gg);
        pair<pair<int,int>,ll>  P;
        bool fffffff = 0;
        // rep(i,n){
        //     cerr << imos[i] << " ";
        // }
        // cerr << endl;
        for(auto y:res2){
            // cerr << y.first.first << " " << y.first.second <<  "   " << imos[y.first.second] <<  endl;
            if(imos[y.first.second]==0){
                // cerr << "ok" << endl;
                if(chmin(mi,y.second+x.second)){
                    ans.clear();
                    P = y;
                    fffffff = 1;
                }
            }
        }
        // cerr << endl;
        if(fffffff){
            int ttt = 0;
            rep(i,m){
                if(edge[i]==P||edge[i]==MP(MP(P.first.second,P.first.first),P.second)){
                    if(i==id)continue;
                    ttt = i;
                    break;
                }
            }
            ans.push_back(id);
            ans.push_back(ttt);
        }
    }
    if(mi==(1LL<<60)){
        cout << -1 << endl;
    }else{
        cout << mi << endl;
        cout << ans.size() << endl;
        for(auto x:ans){
            cout << x+1 << " ";
        }
        cout << endl;
    }
    return 0;
}