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

int a, b, c, d;

bool check(int v){
    return v != a&&v != b&&v != c&&v != d;
}

void solve(){
    int n, k;
    scanf("%d%d%d%d%d%d", &n, &k, &a, &b, &c, &d);
    map<int, int> t;
    t[a]++;
    t[b]++;
    t[c]++;
    t[d]++;
    if (t.size() == 2){
        printf("%d ", a);
        if (a < b){
            for (int i = 1; i < n + 1; ++i){
                if (i != a&&i != b) printf("%d ", i);
            }
        }
        else{
            for (int i = n; i > 0; --i){
                if (i != a&&i != b) printf("%d ", i);
            }
        }
        printf("%d", b);
        puts("");
        printf("%d ", c);
        if (c < d){
            for (int i = 1; i < n + 1; ++i){
                if (i != a&&i != b) printf("%d ", i);
            }
        }
        else{
            for (int i = n; i > 0; --i){
                if (i != a&&i != b) printf("%d ", i);
            }
        }
        printf("%d", d);
        return;
    }
    if (t.size() == 3){
        if (k < n){
            puts("-1");
            return;
        }
        int v;
        for (auto it : t) if (it.y == 2) v = it.x;
        int u = a + b - v;
        vector<int> ans1;
        ans1.pb(v);
        for (int i = 1; i < n + 1; ++i){
            if (check(i)) ans1.pb(i);
        }
        ans1.pb(a + b + c + d - 2 * v - u);
        ans1.pb(u);
        if (v != a) reverse(ans1.begin(), ans1.end());
        for (int i = 0; i < n; ++i){
            printf("%d ", ans1[i]);
        }
        puts("");
        ans1.clear();
        ans1.pb(v);
        for (int i = 1; i < n + 1; ++i){
            if (check(i)) ans1.pb(i);
        }
        ans1.pb(u);
        ans1.pb(a + b + c + d - 2 * v - u);
        for (int i = 0; i < n; ++i){
            printf("%d ", ans1[i]);
        }
        return;
    }
    if (n < 5 || k < n + 1){
        printf("-1");
        return;
    }
    vector<int> ans;
    ans.pb(min(a,b));
    ans.pb(max(c,d));
    for (int i = 1; i < n + 1; ++i){
        if (check(i)) ans.pb(i);
    }
    ans.pb(min(c, d));
    ans.pb(max(a, b));
    if (a > b){
        reverse(ans.begin(), ans.end());
    }
    for (int i = 0; i < n; ++i){
        printf("%d ", ans[i]);
    }
    ans.clear();
    puts("");
    ans.pb(min(c, d));
    ans.pb(max(a, b));
    for (int i = n; i > 0; --i){
        if (check(i)) ans.pb(i);
    }
    ans.pb(min(a, b));
    ans.pb(max(c, d));
    if (c > d){
        reverse(ans.begin(), ans.end());
    }
    for (int i = 0; i < n; ++i){
        printf("%d ", ans[i]);
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