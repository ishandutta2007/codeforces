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


const int N = 500;
vector <long long> v[N];


int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
#endif

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        long long x;
        scanf("%lld", &x);
        int k = 0;
        while (x % (1LL << k) == 0)
            k++;
        v[k].push_back(x);
    }
    int mx = 0;
    for (int i = 0; i < N; i++)
        if (v[i].size() > v[mx].size())
            mx = i;

    vector <long long> ans;
    for (int i = 0; i < N; i++)
        if (i != mx)
            for (long long x : v[i])
                ans.push_back(x);

    printf("%d\n", (int)ans.size());
    for (long long x : ans)
        printf("%lld ", x);
    printf("\n");
    
    return 0;
}