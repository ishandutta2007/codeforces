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
    int n;
    cin >> n;
    vector<int> c(n),t(n);
    rep(i,n){
        cin >> c[i];
    }
    rep(i,n){
        cin >> t[i];
    }
    map<int,int>mp;
    rep(i,n-1){
        mp[c[i+1]-c[i]]++;
    }
    rep(i,n-1){
        mp[t[i+1]-t[i]]--;
    }
    if(c[0]!=t[0]||t[n-1]!=c[n-1]){
        cout << "No\n";
        return 0;
    }
    for(auto x:mp){
        if(x.second!=0){
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";
    return 0;
}