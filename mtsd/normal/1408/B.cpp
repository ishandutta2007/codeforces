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
        vector<int> a(n);
        rep(i,n) cin >> a[i];
        set<int> st;
        rep(i,n)st.insert(a[i]);
        int X = st.size();
        int f = st.count(0);
        if(f)X--;
        if(k==1&&st.size()==1){
            cout << 1 << "\n";
        }else{
            if(k==1){
                cout << -1 << "\n";
            }else{
                int P = 0;
                rep(i,1000){
                    if(!f){
                        P += k;
                        f = 1;
                    }else{
                        P += k-1;
                    }
                    if(P>=X){
                        cout << i+1 << "\n";
                        break;
                    }
                }
            }
        }
    }
    return 0;
}