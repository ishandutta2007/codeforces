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

int a[1001000], ans[1010];

void solve(){
    For(i, 1010) ans[i] = -1;
    For(i, 1001000) a[i] = 0;
    int n, c;
    scanf("%d", &n);
    For(i, n){
        scanf("%d", &c);
        a[c]++;
        if (ans[a[c]] == -1) ans[a[c]] = c;
    }
    int s;
    For(i, 1010) if (ans[i] != -1) s = ans[i];
    printf("%d", s);

}

int main(){
#ifdef _DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    solve();
    return 0;
}