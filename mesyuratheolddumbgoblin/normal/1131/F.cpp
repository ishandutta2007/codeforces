#include <string>
#include <time.h>
#include <vector>
#include <algorithm>
#include <bitset>
#include <utility>
#include <map>
#include <set>
#include <sstream>
#include <iostream>
#include <cmath>
#include <deque>

#define pii pair<ll,ll>
#define MOD 1000000007
#define mp make_pair
#define X first
#define Y second
typedef int ll;
using namespace std;
ll n,m,k, y, z, l, i, j, x;
ll a[100500], p[200500];
vector<ll> f[155000];
int main() {
    //freopen("input.txt", "r", stdin);
    srand(time(0));
    cin >> n;
    for (int i = 1; i <= n; i++) {
        p[i] = i;
        f[i].push_back(i);
    }
    for (int i = 0; i < n-1; i++) {
        scanf("%d %d", &x, &y);
        x = p[x];
        y = p[y];
        if (f[x].size() > f[y].size()) {
            for (auto j : f[y]) {
                p[j] = x;
                f[x].push_back(j);
            }
            f[y].clear();
        } else {
            for (auto j : f[x]) {
                p[j] = y;
                f[y].push_back(j);
            }
            f[x].clear();
        }
    }
    for (auto x : f[p[1]]) {
        printf("%d ", x);
    }
    return 0;
}