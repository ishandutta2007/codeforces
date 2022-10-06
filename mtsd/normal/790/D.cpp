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
int a[300010][2];
int b[300010];
pair<int,int> na[300010][2];
int nb[300010];

map<pair<int,int>,int> mp;

ll dfs(int i,int j){
    if(mp.find(MP(i,j))!=mp.end()){
        return mp[MP(i,j)];
    }
    int k = max(i,j);
    int nk = nb[k];
    int ni = na[i][0].first;
    int ri = na[i][0].second;
    int nj = na[j][1].first;
    int rj = na[j][1].second;
    // cerr << i << " " << j << " " << ni << " " << nj << " "<< ri  << " " << rj  << " " << nk << endl;
    if(nk > ni|| nk > nj){
        if(nk>ni){
            return mp[MP(i,j)] = dfs(ni,j) + 1;
        }else{
            return mp[MP(i,j)] = dfs(i,nj) + 1;
        }
    }
    if(nk!=inf){
        if(ri<=nk&&rj<=nk){
            return mp[MP(i,j)] = max(dfs(nk,nk) + 1,dfs(ni,nj) + 2);
        }else{
            return mp[MP(i,j)] = dfs(nk,nk) + 1;
        }
    }else{
        if(ni==inf&&nj==inf){
            return 0;
        }
        if(ni<nj){
            return mp[MP(i,j)] = dfs(ni,j) + 1;
        }else{
            return mp[MP(i,j)] = dfs(i,nj) + 1;    
        }
    }
    
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    map<ll,int> s[2],u;
    rep(j,2){
        rep(i,n){
            cin >> a[i][j];
        }
    }
    ll c = 0;
    Fill(na,MP(inf,inf));
    Fill(nb,inf);
    rep(j,2){
        c = 0;
        s[j][0] = n;
        for(int i=n-1;i>=0;i--){
            c += a[i][j];
            if(s[j].find(c)!=s[j].end()){
                na[i][j] = MP(s[j][c],i);
            }else{
                na[i][j] = MP(inf,inf);
            }
            s[j][c] = i;
        }
        for(int i=n-2;i>=0;i--){
            chmin(na[i][j],na[i+1][j]);
        }
    }
    c = 0;
    u[0] = n;
    for(int i=n-1;i>=0;i--){
        c += a[i][0]+a[i][1];
        if(u.find(c)!=u.end()){
            nb[i] = u[c];
        }else{
            nb[i] = inf;
        }
        u[c] = i;
    }
    for(int i=n-2;i>=0;i--){
        chmin(nb[i],nb[i+1]);
    }
    cout << dfs(0,0) << endl;
    return 0;
}