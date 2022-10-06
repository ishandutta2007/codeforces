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
int a[]={0,0,4};
int b[]={0,0,0,2,4,6};
int main(){
    ll n,m;
    cin >> n >> m;
    if(n>m)swap(n,m);
    
    if(n>=3){
        cout << (n*m)/2 * 2 << endl;
    }else{
        if(n==2){
            if(m>=4){
                if(m==7){
                    cout << 12 << endl;
                }else{
                    cout << n*m << endl;
                }
            }else{
                cout << a[m-1] << endl;
            }
        }
        if(n==1){
            m--;
            cout << (m/6)*6 + b[m%6] << endl;
        }

    }
    return 0;
}