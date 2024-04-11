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


const int N = (int) 2e5 + 100;
char str[N];


int main()
{
#ifdef LOCAL
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
#endif

    int n;
    scanf("%d", &n);
    scanf("%s", str);

    int bal = 0;
    for (int i = 0; i < n; i++)
    {
        if (str[i] == '(')
            bal++;
        else
            bal--;
        if (bal < -1)
        {
            printf("No\n");
            return 0;
        }
    }
    if (bal != 0)
    {
        printf("No\n");
        return 0;
    }
    printf("Yes\n");


    return 0;
}