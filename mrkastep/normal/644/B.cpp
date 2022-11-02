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

ll ans[200200];

void solve(){
    ll n, b, t, d, T = 0, lf = -1;
    queue<pair<ll, ll> > q;
    scanf("%I64d%I64d", &n, &b);
    For(i, n){
        scanf("%I64d%I64d", &t, &d);
        while (lf != -1 && lf <= t){
            T = lf;
            if (!q.empty()){
                lf = T + q.front().y;
                ans[q.front().x] = lf;
                q.pop();
            }
            else{
                lf = -1;
            }
        }
        T = t;
        if (lf == -1){
            lf = T + d;
            ans[i] = lf;
        }
        else{
            if (q.size() < b){
                q.push(mp(i, d));
            }
            else{
                ans[i] = -1;
            }
        }
    }
    while (lf != -1 && lf <= LONGINF){
        T = lf;
        if (!q.empty()){
            lf = T + q.front().y;
            ans[q.front().x] = lf;
            q.pop();
        }
        else{
            lf = -1;
        }
    }
    For(i, n){
        printf("%I64d ", ans[i]);
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