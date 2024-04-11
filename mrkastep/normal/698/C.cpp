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

double d[1 << 20], s[1 << 20];

double p[21];

int bins(int a){
    int ans = 0;
    while (a > 0) ans += a % 2, a /= 2;
    return ans;
}

double ans[21];

void solve(){
    int n, k, zeroes = 0;
    cin >> n >> k;
    for (int i = 0; i < n; ++i){
        cin >> p[i];
        ans[i] = 0;
        if (p[i] == 0) zeroes++;
    }
    for (int i = 0; i < (1 << n); ++i){
        d[i] = 0;
    }
    d[0] = 1;
    s[0] = 1;
    for (int i = 0; i < (1 << n); ++i){
        for (int j = 0; j < n; ++j){
            if ((1 << j)&i){
                s[i] = s[i ^ (1 << j)] - p[j];
                if(p[j]!=0) d[i] += d[i ^ (1 << j)] * p[j] / s[i ^ (1 << j)];
            }
        }
    }
    for (int i = 0; i < (1 << n); ++i){
        if (bins(i) == min(k,n-zeroes)){
            for (int j = 0; j < n; ++j){
                if (i&(1 << j)){
                    ans[j] += d[i];
                }
            }
        }
    }
    for (int i = 0; i < n; ++i){
        printf("%.10lf ", ans[i]);
    }
}

int main(){
#ifdef _DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    solve();
    return 0;
}