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

    long long p;
    int k;
    scanf("%lld%d", &p, &k);

    vector <long long> v;
    v.push_back(p);
    while (v.back() < 0 || v.back() >= k)
    {
        long long x = v.back();
        long long a = x / k;
        while (a * k <= x) a++;
        while (a * k > x) a--;
        v.back() -= a * k;
        v.push_back(-a);
    }
    printf("%d\n", (int) v.size() );
    for (long long x : v)
        printf("%lld ", x);
    printf("\n");




	return 0;
}