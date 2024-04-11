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
typedef long double ld;

ld dp[51][5100];
int main(){
    int n,R;
    cin >> n >> R;
    vector<int>a(n),b(n);
    vector<ld>p(n),q(n);
    rep(i,n){
        cin >> a[i] >> b[i] >> p[i];
        p[i] /= (ld)100.0;
        q[i] = 1.0-p[i];
    }
    ld ok = 1e18;
    ld ng = 0;
    rep(zz,100){
        ld X = (ok+ng)/2.0;
        // cerr << X << endl;
        rep(i,n){
            rep(j,(100*(i+1))){
                dp[i][j] = X;
            }
        }
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=100*(i+1);j++){
                ld t = 0;
                if(i==n-1){
                    if(j+a[i]>R){
                        t += p[i]*(a[i]+X);
                    }else{
                        t += p[i]*a[i];
                    }
                    if(j+b[i]>R){
                        t += q[i]*(b[i]+X);
                    }else{
                        t += q[i]*b[i];
                    }
                    if(t>X){
                        if(i==0&&j==0){
                        }else{
                            t = X;
                        }
                    }
                    dp[i][j] = t;
                }else{
                    t += p[i]*(a[i]+dp[i+1][j+a[i]]);
                    t += q[i]*(b[i]+dp[i+1][j+b[i]]);
                    if(t>X){
                        if(i==0&&j==0){
                        }else{
                            t = X;
                        }
                    }
                    dp[i][j] = t;    
                }
            }
        }
        ld ss = dp[0][0];    
        cerr << X << " " <<  ss << endl;    
        if(X < ss){
            ng = X;
        }else{
            ok = X;
        }
    }
    cout.precision(30);
    cout << ok << endl;
    return 0;
}