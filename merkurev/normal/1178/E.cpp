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

string ans;

int main()
{
#ifdef LOCAL
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
#endif

    scanf("%s", str);
    char mid = 0;

    int n = strlen(str);
    int l = 0, r = n - 1;
    while (r >= l)
    {
        if (l == r)
        {
            mid = str[l];
            break;
        }
        if (str[l] == str[r])
        {
            ans.push_back(str[l]);
            l++;
            r--;
            continue;
        }
        if (l + 1 == r)
        {
            mid = str[l];
            break;
        }
        if (str[l + 1] == str[r])
        {
            ans.push_back(str[r]);
            l += 2;
            r--;
            continue;
        }
        if (str[l] == str[r - 1])
        {
            ans.push_back(str[l]);
            l++;
            r -= 2;
            continue;
        }
        if (l + 1 == r - 1)
        {
            mid = str[l + 1];
            break;
        }
        ans.push_back(str[l + 1]);
        l += 2;
        r -= 2;
    }
    printf("%s", ans.c_str());
    if (mid)
        printf("%c", mid);
    reverse(ans.begin(), ans.end());
    printf("%s\n", ans.c_str());

    return 0;
}