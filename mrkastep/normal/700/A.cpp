#include <stdio.h> 
#include <iostream> 
#include <vector> 
#include <cstdlib> 
#include <map> 
#include <time.h> 
#include <string> 
#include <algorithm> 
#include <queue> 
#include <assert.h> 
#include <math.h> 
#include <complex>
#include <set>


using namespace std;

const int INF = 2e9;
const int mod = 1e9 + 7;
const long long LONGINF = 4e18;
const double eps = 1e-9;
const double PI = 3.1415926535897932384626433832795;

#define x first
#define y second
#define mp make_pair
#define pb push_back

typedef long long ll;
typedef pair<double, double> point;

void solve(){
    int n, k;
    double l, v1, v2;
    cin >> n >> l >> v1 >> v2 >> k;
    double ans = 0;
    //while (n > 0 && l > 0){
    //    ans += l / v2;
    //    n -= k;
    //    l -= v1*(l / v2);
    //    if (n > 0){
    //        ans += l / (v1 + v2);
    //        l -= l / (v1 + v2)*v1;
    //    }
    //}
    double L = 0, R = LONGINF;
    for (int i = 0; i < 1000; ++i){
        double c = (L + R) / 2;
        if (((n + k - 1) / k)*(l - v1*c) / (v2 - v1) + ((n + k - 1) / k - 1)*(l - v1*c) / (v2 + v1) <= c){
            R = c;
        }
        else{
            L = c;
        }
    }
    printf("%.10lf", L);

}

int main(){
#ifdef _DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    solve();
    return 0;
}