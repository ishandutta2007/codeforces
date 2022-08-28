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


const int N = 25;
string s[N], t[N];

const int LEN = 10500;
char str[LEN];

int main(int,  char **)
{
#ifdef LOCAL
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", str);
        s[i] = string(str);
    }
    for (int i = 0; i < m; i++)
    {
        scanf("%s", str);
        t[i] = string(str);
    }

    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; i++)
    {
        int x;
        scanf("%d", &x);
        x--;
        printf("%s%s\n", s[x % n].c_str(), t[x % m].c_str());
    }


	return 0;
}