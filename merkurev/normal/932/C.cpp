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




int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int n, a, b;
    scanf("%d%d%d", &n, &a, &b);
    
    for (int ca = 0; ca * a <= n; ca++)
    {
        int cb = (n - ca * a) / b;
        if (ca * a + cb * b != n) continue;

        vector <int> ans;
        for (int i = 0; i < ca; i++)
        {
            for (int j = 1; j < a; j++)
                ans.push_back(i * a + j);
            ans.push_back(i * a);
        }
        for (int i = 0; i < cb; i++)
        {
            for (int j = 1; j < b; j++)
                ans.push_back(a * ca + i * b + j);
            ans.push_back(a * ca + i * b);
        }
        for (int x : ans)
            printf("%d ", x + 1);
        printf("\n");

        return 0;
    }
    printf("-1\n");

	return 0;
}