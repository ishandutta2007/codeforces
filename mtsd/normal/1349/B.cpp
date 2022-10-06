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
        int n,k;
        cin >> n >> k;
        vector<int>a(n);
        vector<int>b;
        bool flag = 0;
        rep(i,n){
            cin >> a[i];
            if(a[i]==k)flag = 1;
            if(a[i]>=k){
                b.push_back(i);
            }
        }
        if(!flag){
            cout << "no\n";
        }else{
            if(n==1){
                cout << "yes\n";
            }else{
                int m = b.size();
                bool ok = 0;
                rep(i,m-1){
                    if(b[i+1]-b[i]<=2){
                        ok = 1;
                    }
                }
                if(ok){
                    cout << "yes\n";
                }else{
                    cout << "no\n";
                }
            }
            
        }
    }
    return 0;
}