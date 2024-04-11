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

typedef long long ll;
typedef complex<double> point;



void solve(){
    int n, d, h;
    scanf("%d%d%d", &n, &d, &h);
    if (d == 1 && n > 2 || 2 * h < d){
        puts("-1");
        return;
    }
    for (int i = 0; i < h; ++i){
        printf("%d %d\n", i + 1, i + 2);
    }
    for (int i = 0; i < d - h; ++i){
        if(i==0) printf("%d %d\n", i + 1, i + h + 2);
        else printf("%d %d\n", i + h + 1, i + h + 2);
    }
    if (d == h){
        for (int i = 0; i < n - 1 - d; ++i){
            printf("2 %d\n", i + d + 2);
        }
    }
    else{
        for (int i = 0; i < n - 1 - d; ++i){
            printf("1 %d\n", i + d + 2);
        }
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