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


const int N = 105;
char str[N];

bool isvowel(char c)
{
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main(int,  char **)
{
#ifdef LOCAL
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    scanf("%s", str);
    int len = strlen(str);
    int ans = 0;
    for (int i = 0; i < len; i++)
        if (isdigit(str[i] ) )
        {
            if ( (str[i] - '0') % 2 == 1)
                ans++;
        }
        else
        {
            if (isvowel(str[i] ) )
                ans++;
        }
    printf("%d\n", ans);

	return 0;
}