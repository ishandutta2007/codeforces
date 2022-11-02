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

int n, m;

bool check(int a, int b){
    return a >= 0 && a < n&&b >= 0 && b < m&&s[a][b] == '*';
}

bool check1(int a, int b){
    return a >= 0 && a < n&&b >= 0 && b < m&&s[a][b] == 'S';
}

int p, q;

void dfs(int a, int b){
    if(s[a][b]=='*') s[a][b] = '.';
    p = a;
    q = b;
    if (check(a - 1, b)){
        printf("U");
        dfs(a - 1, b);
        return;
    }
    if (check(a + 1, b)){
        printf("D");
        dfs(a + 1, b);
        return;
    }
    if (check(a, b - 1)){
        printf("L");
        dfs(a, b - 1);
        return;
    }
    if (check(a, b + 1)){
        printf("R");
        dfs(a, b + 1);
        return;
    }
}

void dfs1(int a, int b){
    if (check1(a - 1, b)){
        printf("U");
    }
    if (check1(a + 1, b)){
        printf("D");
    }
    if (check1(a, b - 1)){
        printf("L");
    }
    if (check1(a, b + 1)){
        printf("R");
    }
}

void solve(){
    scanf("%d%d", &n, &m);
    For(i, n) cin >> s[i];
    For(i, n){
        For(j, m){
            if (s[i][j] == 'S') dfs(i, j);
        }
    }
    dfs1(p, q);
}

int main(){
#ifdef _DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    solve();
    return 0;
}