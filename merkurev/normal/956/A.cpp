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


const int N = 55;
char f[N][N];

set <vector <int> > s;

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%s", f[i] );
    for (int i = 0; i < n; i++)
    {
        vector <int> v;
        for (int j = 0; j < m; j++)
            if (f[i][j] == '#')
                v.push_back(j);
        s.insert(v);
    }
    for (auto &x : s)
        for (auto &y : s)
        {
            if (x == y)
                continue;
            for (int i : x)
                for (int j : y)
                    if (i == j)
                    {
                        printf("No\n");
                        return 0;
                    }
        }
    printf("Yes\n");




	return 0;
}