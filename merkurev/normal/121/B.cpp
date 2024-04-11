#ifndef LOCAL
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#endif

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
char str[N];


int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int n, k;
    scanf("%d%d", &n, &k);
    scanf("%s", str);

    set <int> s;

    for (int i = 0; i + 1 < n; i++)
    {
        if (str[i] == '4' && str[i + 1] == '7')
            s.insert(i);
    }

    vector <int> ops;

    while (k > 0)
    {
        if (s.empty())
            break;
        int p = *s.begin();
        s.erase(p);
        if (p % 2 == 1)
        {
            str[p] = '7';
            if (p > 0 && str[p - 1] == '4')
                s.insert(p - 1);
        }
        else
        {
            str[p + 1] = '4';
            if (p + 2 < n && str[p + 2] == '7')
                s.insert(p + 1);
        }
        k--;

        if ((int) ops.size() >= 2 && ops[(int) ops.size() - 2] == p)
        {
            k %= 2;
        }
        ops.push_back(p);
    }

    printf("%s\n", str);

	return 0;
}