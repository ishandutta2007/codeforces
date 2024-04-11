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
    rep(i,n) cin >> a[i];
    sort(all(a));
    int id = 0;
    vector<int> res(n);
    for(int i=1;i<n;i+=2){
        res[i] = a[id];
        id++;
    }
    for(int i=0;i<n;i+=2){
        res[i] = a[id];
        id++;
    }
    int ss = 0;
    for(int i=1;i<n-1;i++){
        if(res[i]<res[i+1]&&res[i]<res[i-1])ss++;
    }
    cout << ss << endl;
    rep(i,n){
        cout << res[i];
        if(i!=n-1)cout << " ";
    }
    cout << endl;
    return 0;
}