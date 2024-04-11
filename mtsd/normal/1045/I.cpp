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
    map<int,ll> mp;   
    int n;
    cin >> n;
    rep(i,n){
        vector<int> a(26);
        string s;
        cin >> s;
        rep(i,s.size()){
            a[s[i]-'a']++;
        }
        int k = 0;
        rep(i,26){
            if(a[i]%2==1){
                k ^= (1<<i);
            }
        }
        mp[k]++;
    }
    ll res = 0;
    for(auto x:mp){
        int bits = x.first;
        res += x.second*(x.second-1);
        rep(i,26){
            if(mp.find(bits^(1<<i))!=mp.end()){
                res += x.second * mp[bits^(1<<i)];
            }
        }
    }
    cout << res/2 << endl;
    return 0;
}