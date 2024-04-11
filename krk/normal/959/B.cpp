#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <map>
#include <iomanip>
using namespace std;

typedef long long ll;

const int Maxn = 100005;

int n, k, m;
char str[Maxn][25];
map <string, int> M;
int cost[Maxn];
int group[Maxn], gcost[Maxn];

int main() {
    scanf("%d %d %d", &n, &k, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%s", str[i]);
        M[str[i]] = i;
    }
    for (int i = 1; i <= n; i++)
        scanf("%d", &cost[i]);
    for (int i = 1; i <= k; i++) {
        gcost[i] = 1000000007;
        int siz; scanf("%d", &siz);
        while (siz--) {
            int a; scanf("%d", &a);
            group[a] = i; gcost[i] = min(gcost[i], cost[a]);
        }
    }
    ll res = 0;
    for (int i = 1; i <= m; i++) {
        char tmp[25]; scanf("%s", tmp);
        res += gcost[group[M[tmp]]];
    }
    cout << res << endl;
	return 0;
}