#include <iostream>
#include <cstdio>
#include <set>
using namespace std;

int n, m, u, v;
set<pair<int, int>> se;

bool check(int add)
{
    for (pair<int, int> v : se)
        if (se.count({(v.first + add) % n, (v.second + add) % n}) == 0)
            return false;
    return true;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d", &u, &v);
        se.insert({u - 1, v - 1});
        se.insert({v - 1, u - 1});
    }
    for (int i = 1; i < n; i++)
        if (n % i == 0 && check(i))
            return printf("Yes"), 0;
    printf("No");
}