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
int a[301][301];
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    rep(zz,t){
        int n,m;
        cin >> n >> m;
        rep(i,n){
            rep(j,m){
                cin >> a[i][j];
            }
        }
        bool ng = 0;
        rep(i,n){
            rep(j,m){
                int s = 4;
                if(i==0||i==n-1)s--;
                if(j==0||j==m-1)s--;
                if(a[i][j]>s){
                    ng = 1;
                }
            }
        }
        if(ng){
            cout << "NO\n";
        }else{
            cout << "YES\n";
            rep(i,n){
                rep(j,m){
                    int s = 4;
                    if(i==0||i==n-1)s--;
                    if(j==0||j==m-1)s--;
                    cout << s << " ";
                }
                cout << "\n";
            }
        }
    }
    return 0;
}