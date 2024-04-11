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

int dist(int a, int b){
    int s = 0;
    For(i, 6){
        if (a % 10 != b % 10) ++s;
        a /= 10;
        b /= 10;
    }
    return s;
}

int a[1010];

void solve(){
    int n, ans = 10;
    scanf("%d", &n);
    if (n == 1){
        printf("6");
        return;
    }
    For(i, n){
        scanf("%d", &a[i]);
    }
    For(i, n){
        For(j, i){
            ans = min(ans, dist(a[i], a[j]));
        }
    }
    printf("%d", (ans-1)/2);
}

int main(){
#ifdef _DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    solve();
    //For(i, 20000){
    //    printf("%c%c%c%c%c%c\n", rand() % 26 + 'a', rand() % 26 + 'a', rand() % 26 + 'a', rand() % 26 + 'a', rand() % 26 + 'a', rand() % 26 + 'a');
    //}
    return 0;
}