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
#include <chrono>
#include <random>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long int int64;


char str[100];
const int BOUND = 80;

int main(int,  char **)
{
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    
    long long n;
    int k;
    scanf("%lld%d", &n, &k);
    long long l = 1;
    long long r = n;

    while (true) 
    {
        if (r - l > BOUND) {
            long long m = (l + r) / 2;
            printf("%lld %lld\n", l, m);
            fflush(stdout);
            scanf("%s", str);
            if (str[0] == 'Y')
                r = m;
            else
                l = m + 1;
        }
        else {
            long long x = l + rng() % (r - l + 1);
            printf("%lld %lld\n", x, x);
            fflush(stdout);
            scanf("%s", str);
            if (str[0] == 'Y')
                break;
        }
        l -= k;
        r += k;
        l = max(l, 1LL);
        r = min(r, n);
    }

	return 0;
}