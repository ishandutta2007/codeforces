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

char co[111][111][111];

#ifdef _DEBUG
int gets(char *dest){
    char c;
    int s = 0;
    while ((!isspace(c = getchar()) || c == ' ') && c != EOF) dest[s++] = c;
    dest[s] = '\0';
    return s;
}
#endif

char tmp[111];

int check(int a, int b, int c, int d, int e, int f){
    if (co[a][b][c] == '0' || co[d][e][f] == '0') return 2;
    if (d - a == 2 || e - b == 2 || f - c == 2){
        return 1;
    }
    int ans = 0;
    if (a != d){
        if (b != e){
            ans = co[a + 1][b][c] - '0' + co[a][b + 1][c] - '0';
        }
        else{
            ans = co[a + 1][b][c] - '0' + co[a][b][c + 1] - '0';
        }
    }
    else{
        ans = co[a][b + 1][c] - '0' + co[a][b][c + 1] - '0';
    }
    return ans;
}

void solve(){
    int n, m, k;
    scanf("%d%d%d\n", &n, &m, &k);
    For(i, 111){
        For(j, 111){
            For(l, 111){
                co[i][j][l] = '0';
            }
        }
    }
    For(i, n){
        For(j, m){
            gets(co[i + 1][j + 1] + 1);
            co[i + 1][j + 1][k + 1] = '0';
        }
        gets(tmp);
    }
    int ans = 0;
    for (int i = 1; i < n + 1; ++i){
        for (int j = 1; j < m + 1; ++j) {
            for (int l = 1; l < k + 1; ++l) {
                if (co[i][j][l] != '0'){
                    int crit = 0;
                    if (check(i - 1, j, l, i + 1, j, l) == 1) crit = 1;
                    if (check(i - 1, j, l, i, j + 1, l) == 1) crit = 1;
                    if (check(i - 1, j, l, i, j, l + 1) == 1) crit = 1;
                    if (check(i, j - 1, l, i + 1, j, l) == 1) crit = 1;
                    if (check(i, j - 1, l, i, j + 1, l) == 1) crit = 1;
                    if (check(i, j - 1, l, i, j, l + 1) == 1) crit = 1;
                    if (check(i, j, l - 1, i + 1, j, l) == 1) crit = 1;
                    if (check(i, j, l - 1, i, j + 1, l) == 1) crit = 1;
                    if (check(i, j, l - 1, i, j, l + 1) == 1) crit = 1;
                    if (crit == 1) ++ans;
                }
            }
        }
    }
    printf("%d", ans);
}

int main(){
#ifdef _DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    solve();
    return 0;
}