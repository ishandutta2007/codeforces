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
ll ans[] = {0,1,2,3,4,5,6,7,8,9,19,29,39,49,59,69,79,89,189,289,389,489,589,689,789,1789,2789,3789,4789,5789,6789,16789,26789,36789,46789,56789,156789,256789,356789,456789,1456789,2456789,3456789,13456789,23456789,123456789};
int main(){
    // map<int,int> mp;
    // rep(i,123456790){
    //     string s = to_string(i);
    //     int n = s.size();
    //     set<char> st;
    //     bool flag = 0;
    //     rep(j,n){
    //         if(st.count(s[j])){
    //             flag = 1;
    //         }
    //         st.insert(s[j]);
    //     }
    //     if(!flag){
    //         int k = 0;
    //         rep(j,n){
    //             k += s[j] -'0'; 
    //         }
    //         if(mp.find(k)==mp.end()){
    //             mp[k] = i;
    //         }
    //     }
    // }
    // cout << "ans[] = {";
    // rep(i,46){
    //     cout << mp[i] << ",";
    // }
    // cout << "}\n";
    int t;
    cin >> t;
    rep(zz,t){
        int n;
        cin >> n;
        if(n >=46){
            cout << -1 << "\n";
            continue;
        }
        cout << ans[n] << "\n";    
    }
    return 0;
}