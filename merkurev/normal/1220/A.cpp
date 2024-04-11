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
const int ALP = 1005;
int cnt[ALP];

int main()
{
#ifdef LOCAL
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
#endif

    int n;
    scanf("%d", &n);
    scanf("%s", str);

    for (int i = 0; i < n; i++)
    {
        cnt[(int)str[i]]++;
    }
    int c0 = cnt['z'], c1 = cnt['n'];

    for (int i = 0; i < c1; i++)
        printf("1 ");
    for (int i = 0; i < c0; i++)
        printf("0 ");

    return 0;
}