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



char str[105];

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
    
    int n;
    scanf("%d", &n);
    string ans = "blue";

    bool locked = false;
    for (int i = 0; i < n; i++)
    {
        scanf("%s", str);
        string cur = string(str);
        if (cur == "lock")
            locked = true;
        else if (cur == "unlock")
            locked = false;
        else if (!locked)
            ans = cur;
    }
    printf("%s\n", ans.c_str());




	return 0;
}