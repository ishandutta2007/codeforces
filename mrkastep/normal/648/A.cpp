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

string s[111];
int a[111];

void solve(){
    int n, m;
    scanf("%d%d", &n, &m);
    For(i, n) cin >> s[i];
    For(i, m){
        for (a[i] = 0; a[i] < n && s[n - a[i] - 1][i] == '*'; ++a[i]);
    }
    int u = 0, d = 0;
    For(i, m - 1){
        u = max(u, a[i + 1] - a[i]);
        d = max(d, a[i] - a[i + 1]);
    }
    printf("%d %d", u, d);
}

int main(){
#ifdef _DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    solve();
    return 0;
}