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

const int INF = 2e9;
const int mod = 1e9 + 7;
const long long LONGINF = 4e18;
const double eps = 1e-9;
const double PI = 3.1415926535897932384626433832795;

#define x first
#define y second
#define mp make_pair
#define pb push_back

typedef long long ll;
typedef pair<double, double> point;

int a[111][111];

vector<pair<int, int> > V;

void solve(){
    int n, m, q;
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            a[i][j] = 1;
        }
    }
    for (int i = 0; i < q; ++i){
        int t, u, v, val;
        scanf("%d", &t);
        if (t == 1){
            scanf("%d", &u);
            --u;
            for (int j = 0; j < m - 1; ++j){
                swap(a[u][j], a[u][j + 1]);
            }
            V.push_back(mp(t, u));
        }
        if (t == 2){
            scanf("%d", &u);
            --u;
            for (int j = 0; j < n - 1; ++j){
                swap(a[j][u], a[j + 1][u]);
            }
            V.push_back(mp(t, u));
        }
        if (t == 3){
            scanf("%d%d%d", &u, &v, &val);
            --u;
            --v;
            a[u][v] = val;
        }
    }
    while (!V.empty()){
        if (V.back().x == 1){
            for (int j = m - 1; j > 0; --j){
                swap(a[V.back().y][j], a[V.back().y][j - 1]);
            }
        }
        else{
            for (int j = n - 1; j > 0; --j){
                swap(a[j][V.back().y], a[j - 1][V.back().y]);
            }
        }
        V.pop_back();
    }
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            printf("%d ", a[i][j]);
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