#include <iostream>
#include <math.h>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>

#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define vec vector
#define deb(x) cerr << #x << " = " << x << '\n';

typedef unsigned long long ull;
typedef long double LD;
typedef long long LL;

const LL inf = 1000000000ll;
const LL inf64 = inf * inf;
const LL base = inf + 7;
const LL MOD = inf + 9;
const double pi = acos(-1.0);

using namespace std;

bool solve()
{
    int n, k, p, x, y;

    scanf("%d%d%d%d%d", &n, &k, &p, &x, &y);

    vec<int> a(k);

    for(int i(0);i < k;i++) {
        scanf("%d", &a[i]);
    }

    sort(ALL(a));

    vec<int> ans(n + 1);

    int j = k - 1;

    for(int i(n);i >= 1 && j >= 0;i--) {
        if(a[j] >= y) {
            ans[i] = a[j];
            j--;
        }else if(a[j] < y) {
            if(i < (n + 1) / 2) ans[i] = a[j], j--;
            else {
                ans[i] = y;
            }
        }
    }

    int cnt = count(ALL(ans), 0) - 1;

    if(j >= 0) {
        puts("-1");
        return true;
    }

    if(ans[(n + 1) / 2] == 0) {
        ans[(n + 1) / 2] = y;
        for(int i((n + 1) / 2 + 1);i <= n && ans[i] == 0;i++) {
            ans[i] = y;
        }
    }

    for(int i(1);ans[i] == 0 && i <= n;i++) {
        ans[i] = 1;
    }

    int sum = 0;
    for(int i(1);i <= n;i++) {
        sum += ans[i];
    }

    if(sum > x) {
        puts("-1");
        return true;
    }

    j = 0;

    for(int i(n);i >= 1;i--) {
        if(a.empty()) printf("%d ", ans[i]);
        else if(a.back() == ans[i]) a.pop_back();
        else printf("%d ", ans[i]);
    }

    puts("");

    return true;
}   

int main() 
{
    //while(solve());
    solve();

    return 0;
}