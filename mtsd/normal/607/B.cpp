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
int res[501][501];
bool flag[501][501];
int n;
vector<int> a;

int solve(int l,int r){
    if(r<l)return 0;
    if(l==r)return 1;
    if(flag[l][r])return res[l][r];
    flag[l][r] = 1;
    int mi = 1 + solve(l+1,r);
    for(int i=l+1;i<=r;i++){
        if(a[l]==a[i]){
            if(i==l+1){
                chmin(mi,1 + solve(i+1,r));
            }else{
                chmin(mi,solve(l+1,i-1) + solve(i+1,r));
            }
        }
    }
    return res[l][r] = mi;
}   

int main(){
    cin >> n;
    a.resize(n);
    rep(i,n){
        cin >> a[i];
    }
    cout << solve(0,n-1) << endl;
    return 0;
}