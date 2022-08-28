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


const int N = 5005;
char str[N];
const int ALP = 26;
int cnt[ALP];
int n;

double solve(vector <int> pos)
{
    if (pos.empty() ) return 0;
    int mx = 0;
    for (int d = 1; d < n; d++)
    {
        memset(cnt, 0, sizeof cnt);
        for (int x : pos)
            cnt[str[(x + d) % n] - 'a']++;
        int good = 0;
        for (int i = 0; i < ALP; i++)
            if (cnt[i] == 1)
                good++;
        mx = max(mx, good);
    }
    return (double) mx / (double) pos.size();
}

vector <int> pos[ALP];
int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    scanf("%s", str);
    n = strlen(str);

    for (int i = 0; i < n; i++)
        pos[str[i] - 'a'].push_back(i);

    double ans = 0;
    for (int i = 0; i < ALP; i++)
    {
        double p = (double) pos[i].size() / (double) n;
        ans += p * solve(pos[i] );
    }
    printf("%.10lf\n", ans);

	return 0;
}