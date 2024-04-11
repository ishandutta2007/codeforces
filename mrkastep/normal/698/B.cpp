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

int a[211111], st[222222];

int root = -1, diff = 0, cnt = 1;

void dfs(int v){
    if (v == root) return;
    if (st[v] != 0){
        if (st[v] == cnt){
            if (root == -1) root = v;
            a[v] = root;
            ++diff;
        }
        return;
    }
    st[v] = cnt;
    dfs(a[v]);

}

void solve(){
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i){
        cin >> a[i];
        --a[i];
        if (a[i] == i) root = i;
        st[i] = 0;
    }
    for (int i = 0; i < n; ++i){
        if (st[i] == 0) dfs(i);
        ++cnt;
    }
    cout << diff << endl;
    for (int i = 0; i < n; ++i){
        printf("%d ", a[i] + 1);
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