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
char str[2][N];
int cnt[2][N][2];
int segA[2][N], len[2];

void readStr(int id)
{
    scanf("%s", str[id] );
    len[id] = strlen(str[id] );
    for (int i = 0; i < len[id]; i++)
        if (str[id][i] == 'C') str[id][i] = 'B';

    for (int i = 0; i < len[id]; i++)
    {
        cnt[id][i + 1][0] = cnt[id][i][0];
        cnt[id][i + 1][1] = cnt[id][i][1];
        cnt[id][i + 1][str[id][i] - 'A']++;
    }
    for (int i = 0; i < len[id]; i++)
    {
        segA[id][i] += 1;
        if (str[id][i] == 'B') segA[id][i] = 0;
        segA[id][i + 1] = segA[id][i];
    }
}


int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    for (int i = 0; i < 2; i++)
        readStr(i);
    int q;
    scanf("%d", &q);
    for (int it = 0; it < q; it++)
    {
        int ccnt[2][2], endA[2];
        for (int t = 0; t < 2; t++)
        {
            int l, r;
            scanf("%d%d", &l, &r);
            l--;
            r--;
            for (int x = 0; x < 2; x++)
                ccnt[t][x] = cnt[t][r + 1][x] - cnt[t][l][x];
            endA[t] = min(segA[t][r], r - l + 1);
        }
        int ans = 1;
        if (ccnt[0][1] % 2 != ccnt[1][1] % 2) ans = 0;
        if (ccnt[1][1] < ccnt[0][1] ) ans = 0;
        if (endA[1] > endA[0] ) ans = 0;
        if (endA[1] < endA[0] && endA[1] % 3 != endA[0] % 3 && ccnt[0][1] == ccnt[1][1] ) ans = 0;
        if (endA[1] == endA[0] && ccnt[0][1] == 0 && ccnt[1][1] != 0) ans = 0;
        printf("%d", ans);
    }
    printf("\n");

	return 0;
}