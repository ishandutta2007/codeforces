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
double p[2010][2010];
bool c[2010],r[2010];
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    rep(i,m){
        int a,b;
        cin >> a >> b;
        a--;b--;
        c[a] = 1;
        r[b] = 1;
    }
    int a = 0;
    int b = 0;
    rep(i,n){
        if(!c[i])a++;
    }
    rep(i,n){
        if(!r[i])b++;
    }
    if(a==0&&b==0){
        cout << 0 << endl;
        return 0;
    }
    p[a][b] = 1;
    for(int i=a;i>=0;i--){
        for(int j=b;j>=0;j--){
            double A = 0;
            A += (double)(i*(n-j));
            A += (double)((n-i)*j);
            A += (double)((i)*(j));
            if(i!=0)p[i-1][j] += (double)(i*(n-j))/A*p[i][j];
            if(j!=0)p[i][j-1] += (double)((n-i)*j)/A*p[i][j];
            if(i!=0&&j!=0)p[i-1][j-1] += (double)((i)*(j))/A*p[i][j];
        }
    }
    
    double res = 0;
    rep(i,a+1){
        rep(j,b+1){
            if(i==0&&j==0)continue;
            // cerr << i << " " << j << " " << p[i][j] << " " << p[i][j]*(double)(n*n)/(double)(n-i)*(n-j) << endl;
            // res += p[i][j];
            if(i!=0||j!=0){
                double A = 0;
                A += (double)(i*(n-j));
                A += (double)((n-i)*j);
                A += (double)((i)*(j));
                A /= (double)(n*n);
                // cerr << 1.0/A << endl;
                res += p[i][j] * (1.0)/(A);
            }
        }
    }
    cout << fixed << setprecision(20) << res << endl;
    return 0;
}