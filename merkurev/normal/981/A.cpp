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
char str[N];

int main(int,  char **)
{
#ifdef LOCAL
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    scanf("%s", str);
    int n = strlen(str);
    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++)
        {
            bool good = false;
            for (int t = 0; t <= j - i; t++)
                if (str[i + t] != str[j - t] ) good = true;
            if (good) ans = max(ans, j - i + 1);
        }
    printf("%d\n", ans);

	return 0;
}