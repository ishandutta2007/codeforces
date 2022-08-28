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


const int N = 300500;
int c[N], ans[N];

set <pair <int, int> > s;

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
        scanf("%d", &c[i] );

    long long sumc = 0, anst = 0;
    for (int i = 0; i < k; i++)
    {
        sumc += c[i];
        s.insert(make_pair(c[i], i) );
        anst += sumc;
    }
    for (int i = k; i < k + n; i++)
    {
        if (i < n)
        {
            sumc += c[i];
            s.insert(make_pair(c[i], i) );
        }
        auto p = *s.rbegin();
        s.erase(p);
        sumc -= p.first;
        anst += sumc;
        ans[p.second] = i;
    }
    printf("%lld\n", anst);
    for (int i = 0; i < n; i++)
        printf("%d ", ans[i] + 1);
    printf("\n");



	return 0;
}