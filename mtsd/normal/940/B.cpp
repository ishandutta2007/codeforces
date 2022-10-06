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
ll n,k,a,b;
map<ll,ll> mp;
ll dfs(ll x){
    if(x==1)return 0;
    if(x<k)return (x-1)*a;
    if(mp.find(x)!=mp.end()){
        return mp[x];
    }
    ll mi = (x-1)*a;
    ll nxt = (x/k)*k;
    chmin(mi,(x-nxt)*a + b + dfs(nxt/k));
    return mp[x] = mi;
}
int main(){
    cin >> n >> k >> a >> b;
    if(k==1){
        cout << (n-1)*a << endl;
    }else{
        cout << dfs(n) << endl;
    }
    return 0;
}