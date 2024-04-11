#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
#include <numeric>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long int int64;

const int N = (int) 1e5 + 100;
int l[N], r[N];
vector <pair <int, int>> ls, rs;
bool used[N];
int pos[N], mt[N];
bool sw[N];

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &l[i], &r[i]);
        ls.emplace_back(l[i], i);
        rs.emplace_back(r[i], i);
    }
    if (n == 1)
    {
        printf("%d\n", max(l[0], r[0]) + 1);
        return 0;
    }

    sort(ls.begin(), ls.end() );
    sort(rs.begin(), rs.end() );

    for (int i = 0; i < n; i++)
    {
        pos[ls[i].second] = i;
        mt[ls[i].second] = rs[i].second;
    }
/*    for (int i = 0; i < n; i++)
    {
        int x = ls[i].second;
        if (used[x]) continue;
        int mx = 0;
        while (!used[x])
        {
            mx = max(mx, pos[x]);
            used[x] = true;
            x = mt[x];
        }
        if (mx != n - 1)
            sw[mx] = true;
    }
//    for (int i = 0; i < n; i++)
//       eprintf("%d %d\n", mt[i], sw[i]);
    for (int i = 0; i < n; i++)
    {
        if (!sw[i]) continue;
        int j = i;
        while (sw[j]) j++;
        for (int x = i + 1; x <= j; x++)
            mt[ls[x].second] = rs[x - 1].second;
        mt[ls[i].second] = rs[j].second;
        i = j;
    }
    for (int i = 0; i < n; i++)
        eprintf("%d %d\n", mt[i], sw[i]);
*/    long long ans = n;
    for (int i = 0; i < n; i++)
        ans += max(l[i], r[mt[i]]);
    printf("%lld\n", ans);

	return 0;
}