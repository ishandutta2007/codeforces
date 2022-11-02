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

#define For(i,n) for(int i=0;i<(n);i++) 
#define FOR(i,a,b) for(int i=(a);i<(b);i++) 
#define pb push_back 
#define mp make_pair 
#define x first 
#define y second 
#define all(v) (v).begin(),(v).end() 

typedef long long int ll;
typedef vector<ll> lll;
typedef complex<double> point;

const int INF = 2e9;
const int mod = 1e9 + 7;
const ll LONGINF = 4e18;
const double eps = 1e-9;
const double PI = 3.1415926535897932384626433832795;

int ans[111][111];

void solve(){
    int n, a, b;
    scanf("%d%d%d", &n, &a, &b);
    if (a*b < n){
        printf("-1");
        return;
    }
    For(i, 111) For(j, 111) ans[i][j] = 0;
    int s = 1;
    for (int i = 0, t = 1; i < a; ++i, t *= -1){
        for (int j = (t == 1) ? 0 : b - 1; j != -1 && j != b; j += t, ++s){
            if (s <= n) ans[i][j] = s;
        }
    }
    For(i, a){
        For(j, b){
            printf("%d ", ans[i][j]);
        }
        puts("");
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