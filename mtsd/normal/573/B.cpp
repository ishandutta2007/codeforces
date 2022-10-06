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
int p[100010];
int q[100010];
int main(){
    int n;
    cin >> n;
    vector<int> a(n+2);
    rep(i,n){
        cin >> a[i+1];
    }
    a[0] = 0;
    a[n+1] = 0;
    rep(i,n+2){
        if(i==0)p[i] = 0;
        else{
            p[i] = min(p[i-1]+1,a[i]);
        }
    }
    for(int i=n+1;i>=0;i--){
        if(i==n+1)q[i] = 0;
        else{
            q[i] = min(q[i+1]+1,a[i]);
        }
    }
    int ma = 0;
    for(int i=1;i<=n;i++){
        chmax(ma,min(p[i],q[i]));
    }
    cout << ma << endl;
    return 0;
}