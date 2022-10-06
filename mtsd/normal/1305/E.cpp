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

bool ok(int n,int m){
    int sm = 0;
    for(int i=n-2;i>=0;i-=2){
        sm += i;
    }
    if(sm>=m)return true;
    else return false;
}

int res[5001];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    rep(i,n){
        res[i] = 10000*i+100000000;
    }
    if(!ok(n,m)){
        cout << -1 << endl;
        return 0;
    }
    if(m==0){
        rep(i,n){
            cout << res[i] << " ";
        }
        cout << endl;
        return 0;
    }
    res[0] = 1;
    res[1] = 2;
    res[2] = 3;
    int sm = 1;
    for(int i=3;i<n;i++){
        if(sm==m)break;
        if(sm + i/2 < m){
            sm += i/2;
            res[i] = i+1;
        }else{
            int tmp = res[i-1]+res[i-2];
            if(i%2==1){
                tmp--;
            }
            sm++;
            while(sm<m){
                tmp -=2;
                sm++;
            }
            res[i] = tmp;
            break;
        }
    }
    rep(i,n){
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}