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
char str[N];

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
#endif

    scanf("%s", str);
    int n = strlen(str);
    char mn = str[0];
    for (int i = 0; i < n; i++)
    {
        if (str[i] > mn)
            printf("Ann\n");
        else
            printf("Mike\n");
        mn = min(mn, str[i]);
    }

    return 0;
}