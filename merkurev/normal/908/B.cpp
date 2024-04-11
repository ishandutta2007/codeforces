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

const int DX[4] = {-1, 0, 0, 1};
const int DY[4] = {0, -1, 1, 0};

const int N = 105;
int n, m;
char f[N][N];
char str[N];
int p[4];

bool inF(int x, int y)
{
    return x >= 0 && x < n && y >= 0 && y < m;
}

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; i++)
        scanf("%s", f[i] );
    scanf("%s", str);
    int len = strlen(str);
    for (int i = 0; i < len; i++)
        str[i] -= '0';
    for (int i = 0; i < 4; i++)
        p[i] = i;
    int ans = 0;

    do
    {
        int x = -1, y = -1;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (f[i][j] == 'S')
                {
                    x = i;
                    y = j;
                }
        bool win = false;
        for (int i = 0; i < len; i++)
        {
            int d = p[(int)str[i] ];
            x += DX[d];
            y += DY[d];
            
            if (!inF(x, y) || f[x][y] == '#')
                break;
            if (f[x][y] == 'E')
            {
                win = true;
                break;
            }
        }
        if (win) ans++;
    }
    while (next_permutation(p, p + 4) );

    printf("%d\n", ans);


	return 0;
}