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

string s;
int a[100100], sb[100100];

void solve(){
    int n, k;
    scanf("%d%d", &n, &k);
    cin >> s;
    For(i, n){
        a[i] = '1' - s[i];
    }
    sb[0] = a[0];
    FOR(i, 1, n) sb[i] = sb[i - 1] + a[i];
    int l = 0, r = n;
    while (r - l > 1){
        int c = (l + r) / 2;
        For(i, n){
            int t = 0;
            if (i > 0){
                t += sb[i - 1];
                if (i > c){
                    t -= sb[i - c - 1];
                }
            }
            t += sb[min(n-1,i+c)]-sb[i];
            if (a[i] == 1 && t >= k){
                r = c;
                break;
            }
        }
        if (r != c){
            l = c;
        }
    }
    printf("%d", r);


}

int main(){
#ifdef _DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    solve();
    return 0;
}