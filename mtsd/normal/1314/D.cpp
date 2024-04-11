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
int dst[81][81];
bool black[81];
int n,k;
int s;
int tt;
int d[6][6];
int p[6];
int q[6];

pair<int,int> dd[7][81][81];

int calc(){
    vector<int> a;
    rep(i,n){
        if(black[i])a.push_back(i);
    }
    rep(i,tt){
        rep(j,tt){
            d[i][j] = inf;
        }
    }
    rep(i,tt){
        rep(j,tt){
            rep(k,min(5,n-2)){
                if(black[dd[k][a[i]][a[j]].second])continue;
                d[i][j] = dd[k][a[i]][a[j]].first;
                break;
            }
        }
    }
    rep(zz,tt){
        p[zz] = inf;
    }
    p[0] = 0;
    rep(zz,s){
        rep(ii,tt){
            q[ii] = inf;
        }
        rep(i,tt){
            rep(j,tt){
                chmin(q[j],p[i]+d[i][j]);
            }
        }
        rep(ii,tt){
            p[ii] = q[ii];
        }
    }
    // cerr << tt <<  " test" << endl;
    // for(auto x:a){
    //     cerr << x << " ";
    // }
    // cerr << endl;
    // cerr << p[0] << endl;
    return p[0];
}

int dfs(int id,int c){
    if(n<=tt)return inf;
    if(id==n&&c < tt)return inf;
    if(tt==c){
        return calc();
    }else{
        int mi = inf;
        for(int i=id;i<n;i++){
            black[i] = 1;
            chmin(mi,dfs(i+1,c+1));
            black[i] = 0;
        }   
        return mi;
    }
}


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> k;
    rep(i,n){
        rep(j,n){
            cin >> dst[i][j];
        }
    }
    if(n==2){
        int sm = dst[0][1]+dst[1][0];
        cout << sm *(k/2) << endl;
        return 0;
    }
    rep(i,n){
        rep(j,n){
            vector<pair<int,int> > a;
            rep(k,n){
                if(i==k||j==k)continue;
                a.push_back(MP(dst[i][k]+dst[k][j],k));
            }
            sort(a.begin(),a.end());
            rep(tt,min(5,n-2)){
                dd[tt][i][j] = a[tt];
            }
        }
    }

    black[0] = 1;
    s = k/2;
    int mi = inf;
    for(int i=1;i<=s;i++){
        tt = i;
        chmin(mi,dfs(1,1));
    }
    cout << mi  << endl;
    return 0;
}