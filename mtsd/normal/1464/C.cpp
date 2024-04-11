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
    ll T;
    cin >> n >> T;
    string s;
    cin >> s;
    T -= (1LL<<(s.back()-'a'));
    s.pop_back();
    T += (1LL<<(s.back()-'a'));
    s.pop_back();
    n-=2;
    vector<ll> a(26);
    rep(i,n){
        a[s[i]-'a']++;
    }
    for(int i=25;i>=0;i--){
        ll k = (1LL<<i);
        ll c = a[i];
        rep(zz,c){
            if(T<0){
                T += k;
            }else{
                T -= k;
            }
        }
    }
    if(T==0){
        cout << "Yes\n";
    }else{
        cout << "No\n";
    }
    return 0;
}