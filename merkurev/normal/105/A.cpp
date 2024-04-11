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
map <string, int> ms;


int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
    
    int n, m;
    double _k;
    scanf("%d%d%lf", &n, &m, &_k);
    int k = (int) (_k * 100 + 0.5);

    for (int i = 0; i < n; i++)
    {
        int val;
        scanf("%s%d", str, &val);
        string s = string(str);
        int newVal = (val * k) / 100;
        if (newVal < 100)
            continue;
        ms[s] = newVal;
    }

    for (int i = 0; i < m; i++)
    {
        scanf("%s", str);
        string s = string(str);
        ms[s] += 0;
    }

    printf("%d\n", (int) ms.size());
    for (auto p : ms)
        printf("%s %d\n", p.first.c_str(), p.second);


	return 0;
}