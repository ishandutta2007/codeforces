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

int sb[2002000], ans[2002000];

string s;

void solve(){
    int lst[26], n, m, k;
    For(i, 26) lst[i] = -1;
    sb[1] = 0;
    scanf("%d%d", &n, &k);
    cin >> s;
    m = s.size();
    For(i, m){
        if (lst[s[i] - 'a'] == -1){
            if (i > 0) ans[i] = sb[i - 1] + 1;
            else ans[i] = 1;
        }
        else{
            ans[i] = (sb[i - 1] - sb[lst[s[i] - 'a']] + mod) % mod + ans[lst[s[i] - 'a']];
            ans[i] %= mod;
        }
        sb[i] = ans[i];
        if (i > 0){
            sb[i] += sb[i - 1];
            sb[i] %= mod;
        }
        lst[s[i] - 'a'] = i;
    }
    FOR(i, m, n + m){
        char nxt = 'a';
        int mn = lst[0];
        For(j, k){
            if (lst[j] < mn){
                nxt = 'a' + j;
                mn = lst[j];
            }
        }
        s += nxt;
        if (lst[s[i] - 'a'] == -1){
            if (i > 0) ans[i] = sb[i - 1] + 1;
            else ans[i] = 1;
        }
        else{
            ans[i] = (sb[i - 1] - sb[lst[s[i] - 'a']] + mod) % mod + ans[lst[s[i] - 'a']];
            ans[i] %= mod;
        }
        sb[i] = ans[i];
        if (i > 0){
            sb[i] += sb[i - 1];
            sb[i] %= mod;
        }
        lst[s[i] - 'a'] = i;
    }
    printf("%d", (sb[n + m - 1] + 1) % mod);
}

int main(){
#ifdef _DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    solve();
    return 0;
}