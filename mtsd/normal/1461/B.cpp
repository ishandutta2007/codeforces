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
    int t;
    cin >> t;
    rep(zz,t){
        int n,m;
        cin >> n >> m;
        vector<string> s(n);
        rep(i,n)cin >> s[i];
        int res = 0;
        vector<vector<bool>> p(n,vector<bool>(m));
        vector<vector<bool>> q(n,vector<bool>(m));
        rep(i,n){
            rep(j,m)if(s[i][j]=='*')p[i][j] = 1;
        }
        while(1){
            bool flag = 0;
            rep(i,n){
                rep(j,m){
                    if(p[i][j]){
                        res++;
                        flag = 1;
                        if(i+1 < n && j-1>=0&&j+1<m&&p[i+1][j]&&p[i+1][j-1]&&p[i+1][j+1]){
                            q[i][j] = 1;
                        }
                    }        
                }   
            }
            if(!flag)break;
            rep(i,n)rep(j,m){
                p[i][j] = q[i][j];
                q[i][j] = 0;
            }
        }
        cout << res << "\n";

    }
    return 0;
}