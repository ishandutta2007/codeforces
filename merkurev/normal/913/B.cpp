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



const int N = 1005;
int p[N], ch[N], chleaf[N];


int main(int,  char **)
{
#ifdef LOCAL
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int n;
    scanf("%d", &n);
    for (int i = 1; i < n; i++)
    {
        scanf("%d", &p[i] );
        p[i]--;
        ch[p[i] ]++;
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (ch[i] == 0)
            chleaf[p[i]]++;
        else if (chleaf[i] < 3)
        {
            printf("No\n");
            return 0;
        }
    }
    printf("Yes\n");



	return 0;
}