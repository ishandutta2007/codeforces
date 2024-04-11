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
    int m;
    cin >> m;
    m++;
    vector<int>a(m);
    rep(i,m)cin >> a[i];
    int n = 0;
    rep(i,m)n += a[i];
    bool flag = 0;
    rep(i,m-1){
        if(a[i]>=2&&a[i+1]>=2){
            flag = 1;
        }
    }
    if(!flag){
        cout << "perfect\n";
    }else{
        vector<int> p(n);
        vector<int> q(n);
        int s = 0;
        rep(i,m){
            if(i==0){
                rep(j,a[i]){
                    p[s+j] = s;
                    q[s+j] = s;
                }
            }else{
                if(a[i]>=2&&a[i-1]>=2){
                    rep(j,a[i]){
                        p[s+j] = s;
                        q[s+j] = s - j%2;
                    }
                }else{
                    rep(j,a[i]){
                        p[s+j] = s;
                        q[s+j] = s;
                    }
                }
            }
            s += a[i];
        }   
        cout << "ambiguous\n";
        rep(i,n){
            cout << p[i] << " ";
        }
        cout << "\n";
        rep(i,n){
            cout << q[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}