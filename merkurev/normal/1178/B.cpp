#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <cstring>
#include <string>
using namespace std;

#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...)
#endif


const int N = (int) 1e6 + 100;
char s[N];


int main()
{
#ifdef LOCAL
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    scanf("%s", s);
    long long w = 0, wo = 0, wow = 0;
    int n = strlen(s);
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'v' && s[i + 1] == 'v')
        {
            w += 1;
            wow += wo;
        }
        else if (s[i] == 'o')
        {
            wo += w;
        }
    }
    printf("%lld\n", wow);

    return 0;
}