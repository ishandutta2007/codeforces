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
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> c(n);
    rep(i,n){
        cout << "? " << i << " " << 0 << endl;
        cin >> a[i];
        cout << "? " << 0 << " " << i << endl;
        cin >> c[i];
    }
    vector<int> res;
    int cnt = 0;
    rep(X,n){
        vector<int> b(n);
        vector<int> inv(n);
        vector<bool> used(n);
        b[0] = X;
        inv[X] = 0;
        used[X] = 1;
        bool flag = 1;
        rep(i,n-1){
            b[i+1] = (X^a[0]^a[i+1]);
            if(b[i+1]>=n){
                flag = 0;
                break;
            }
            if(used[b[i+1]]){
                flag = 0;
                break;
            }
            used[b[i+1]] = 1;
            inv[b[i+1]] = i+1;
        }

        rep(i,n){
            if((c[i]^X)!=inv[i])flag = 0;
        }
        if(flag){
            if(res.size()==0){
                res = b;
            }
            cnt++;
        }
    }
    cout << "!" << endl;
    cout << cnt << endl;
    if(cnt!=0){
        rep(i,n){
            cout << res[i];
            if(i!=n-1)cout << " ";
        }
        cout << endl;
    }
    return 0;
}