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
signed main(){
    int n;
    cin >> n;
    rep(i,n){
        int sa,a;
        cin >> sa;
        a = sa;
        bool flag = 0;
        int k = 1;
        while(a!=0){
            if(a%2==0)flag = 1;
            k *= 2;
            a /= 2;
        }
        if(flag){
            cout << k-1 << "\n";
        }else{
            int p = -1;
            for(int i=2;i<sqrt(sa)+3;i++){
                if(sa%i==0){
                    p = max(p,sa/i);
                }
            }
            if(p!=-1){
                cout << p << "\n";
            }else{
                cout << 1 << "\n";
            }
        }
        
    }   
    return 0;
}