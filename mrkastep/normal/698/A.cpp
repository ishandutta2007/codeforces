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

int a[111],d[111][3];

void solve(){
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i){
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i){
        d[i][0] = d[i][1] = d[i][2] = INF;
    }
    d[0][0] = d[0][1] = d[0][2] = 0;
    for (int i = 0; i < n; ++i){
        if (a[i] & 1){
            d[i + 1][1] = min(d[i + 1][1], d[i][0]);
            d[i + 1][1] = min(d[i + 1][1], d[i][2]);
        }
        if (a[i] & 2){
            d[i + 1][2] = min(d[i + 1][2], d[i][0]);
            d[i + 1][2] = min(d[i + 1][2], d[i][1]);
        }
        d[i + 1][0] = min(d[i][0], min(d[i][1], d[i][2])) + 1;
    }
    cout << min(d[n][0], min(d[n][1], d[n][2]));

}

int main(){
#ifdef _DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    solve();
    return 0;
}