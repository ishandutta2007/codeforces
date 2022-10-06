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
    ll a,b,c,d;
    cin >> a >> b >> c >> d;
    if(a==0&b==0&&c==0){
        ll k = 0;
        for(ll i=1;i<=300000;i++){
            if(i*(i-1)/2 > d){
                k = i-1;
                break;
            }
        }
        if(k*(k-1)/2 == d){
            rep(i,k){
                cout << 1;
            }
            cout << "\n";
        }else{
            cout << "Impossible\n";
        }
        return 0;
    }
    if(b==0&c==0&&d==0){
        ll k = 0;
        for(ll i=1;i<=300000;i++){
            if(i*(i-1)/2 > a){
                k = i-1;
                break;
            }
        }
        if(k*(k-1)/2 == a){
            rep(i,k){
                cout << 0;
            }
            cout << "\n";
        }else{
            cout << "Impossible\n";
        }
        return 0;
    }
    ll x = 0, y = 0;
    for(ll i=1;i<=300000;i++){
        if(i*(i-1)/2 > a){
            x = i-1;
            break;
        }
    }
    for(ll i=1;i<=300000;i++){
        if(i*(i-1)/2 > d){
            y = i-1;
            break;
        }
    }
    if(x*(x-1)/2!=a||y*(y-1)/2!=d){
        cout << "Impossible\n";
        return 0;
    }
    ll sm = a+b + c + d;
    if(sm!=(x+y)*(x+y-1)/2){
        cout << "Impossible\n";
        return 0;
    }
    int n = x+y;
    vector<int> res(n);

    rep(i,n){
        if(x>0&&b >= y){
            res[i] = 0;
            b-=y;
            x--;
        }else{
            res[i] = 1;
            y--;
        }
    }
    rep(i,n){
        cout << res[i];
    }
    cout << "\n";
    return 0;
}