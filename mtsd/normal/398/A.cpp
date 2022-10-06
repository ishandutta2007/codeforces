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
    ll a,b;
    cin >> a >> b;
    // if(a>b){
    //     cout << a*a - b*b << endl;
    //     rep(i,a){
    //         cout << "o";
    //     }
    //     rep(i,b){
    //         cout << "x";
    //     }
    //     cout << "\n";
    // }else{
        if(a==0){
            cout << - b*b << "\n";
            rep(zz,b){
                cout << "x";
            }
            cout << endl;
            return 0;
        }
        ll A = 0;
        ll res = -(1LL<<60);
        for(ll p = 2;p<=a+1;p++){    
            ll d = b/(p);
            ll k = b%(p);
            if(chmax(res,(p-2)*1 + (a-p+2)*(a-p+2)-k*(d+1)*(d+1)-(p-k)*d*d)){
                A = p;
            }
        }
        vector<ll> c;
        ll d = b/(A);
        ll k = b%(A);
        rep(i,A){
            c.push_back(d);
        }
        rep(i,k)c[i]++;
        cout << res << "\n";
        rep(i,A){
            rep(j,c[i])cout << "x";
            if(i!=A-1&&i!=A-2)cout << "o";
            if(i==A-2){
                rep(zz,a-A+2)cout<< "o";
            }
        }
        cout << "\n";
    // }
    return 0;
}