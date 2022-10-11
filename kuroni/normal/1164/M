#include <iostream>
#include <cstdio>
#include <set>
using namespace std;

const int N = 100005;

int n, k, u;
bool chk[N];
set<pair<int, int>> se;

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= k; i++)
    {
        scanf("%d", &u);
        chk[u] = true;
        for (int j = u - 1; j <= u + 1; j++)
            if (chk[j])
                se.insert({j, u});
    }
    printf("%d\n", 3 * n - 2 - (int)se.size());
}