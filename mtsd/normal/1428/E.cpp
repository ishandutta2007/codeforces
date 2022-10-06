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
#define int long long

int calc(int a,int b){
    if(a<b)return inf;
    int k = a/b;
    int s = a%b;
    return k*k*(b-s) + (k+1)*(k+1)*s;
}
signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    ll res = 0;
    vector<int> d(n,1);
    priority_queue<pair<int,int> > pq;
    rep(i,n){
        res += calc(a[i],1);
        pq.push(MP(calc(a[i],1)-calc(a[i],2),i));
    }
    rep(i,k-n){
        auto x = pq.top();
        pq.pop();
        int id = x.second;
        res -= x.first;
        d[id]++;
        pq.push(MP(calc(a[id],d[id])-calc(a[id],d[id]+1),id));
    }
    cout << res << endl;
    return 0;
}