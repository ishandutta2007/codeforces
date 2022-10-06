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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,w,h;
    cin >> n >> w >> h;
    map<int,vector<pair<int,int> > >a,b;
    vector<pair<int,int> > res(n);
    
    rep(i,n){
        int g,p,t;
        cin >> g >> p >> t;
        if(g==1){
            a[p-t].push_back({p,i});
            res[i] = {p,h};
        }else{
            b[p-t].push_back({p,i});
            res[i] = {w,p};
        }
    }
    for(auto &x:a){
        sort(all(x.second));
    }
    for(auto &x:b){
        sort(all(x.second));
    }
    
    for(auto &x:b){
        int t = x.first;
        if(a.find(t)!=a.end()){
            auto& q = x.second;
            auto& p = a[t];
            int kkk = 0;
            for(int i=0;i<q.size();i++){
                if(kkk >= p.size()){
                    res[q[(int)q.size()-1-i].second] = {w,q[(int)q.size() -1 - (kkk-(int)p.size())].first};    
                }else{
                    res[q[(int)q.size()-1-i].second] = {p[kkk].first,h};
                }
                kkk++;
            }
            for(int i=0;i<p.size();i++){
                if(kkk >= p.size()){
                    res[p[i].second] = {w,q[(int)q.size() -1 - (kkk-(int)p.size())].first};    
                }else{
                    res[p[i].second] = {p[kkk].first,h};
                }
                kkk++;
            }
        }
    }
    
    
    rep(i,n){
        cout << res[i].first << " " << res[i].second << "\n";
    }
    return 0;
}