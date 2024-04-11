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
multiset <long long> s;
long long v[N], t[N];


int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%lld", &v[i] );
    for (int i = 0; i < n; i++)
        scanf("%lld", &t[i] );

    long long sadd = 0;
    for (int i = 0; i < n; i++)
    {
        s.insert(-sadd + v[i] );
        long long cur = t[i] * (long long) s.size();
        sadd -= t[i];
//        eprintf("cur = %lld\n", cur);
        while (!s.empty() && *s.begin() + sadd <= 0)
        {
//            eprintf("add %lld\n", *s.begin() + sadd);
            cur += *s.begin() + sadd;
            s.erase(s.begin() );
        }
        printf("%lld ", cur);
    }
    printf("\n");



	return 0;
}