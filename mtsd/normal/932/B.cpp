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
int calc(int n){
    if(n<10)return n;
    int k = 1;
    while(n!=0){
        if(n%10){
            k *= (n%10);
        }
        n/=10;
    }
    return calc(k);
}
int res[1000010][10];
int main(){
    for(int i=1;i<=1000000;i++){
        res[i][calc(i)]++;
    }    
    for(int i=1;i<=1000000;i++){
        for(int j=1;j<=9;j++){
            res[i][j] += res[i-1][j];
        }
    }
    cin.tie(0);
    ios::sync_with_stdio(false);
    int q;
    cin >> q;
    rep(zz,q){
        int l,r,k;
        cin >> l >> r >> k;
        cout << res[r][k]-res[l-1][k] << "\n";
    }
    return 0;
}