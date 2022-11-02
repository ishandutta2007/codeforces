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

vector<string> v1(2), v2(2);

void solve(){
    cin >> v1[0];
    cin >> v1[1];
    cin >> v2[0];
    cin >> v2[1];
    For(i, 2){
        if (v1[i][1] == 'X') swap(v1[i][1], v1[i][0]);
        if (v2[i][1] == 'X') swap(v2[i][1], v2[i][0]);
    }
    if (v1[0][0] == 'X') swap(v1[0][0], v1[1][0]);
    if (v2[0][0] == 'X') swap(v2[0][0], v2[1][0]);
    For(i, 3){
        if (v1 == v2){
            puts("YES");
            return;
        }
        swap(v1[0][0], v1[0][1]);
        swap(v1[0][1], v1[1][1]);
    }
    puts("NO");
}

int main(){
#ifdef _DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    solve();
    return 0;
}