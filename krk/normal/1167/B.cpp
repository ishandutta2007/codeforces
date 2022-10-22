#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int nums[6] = {4, 8, 15, 16, 23, 42};

int Get(int a, int b)
{
    printf("? %d %d\n", a, b); fflush(stdout);
    int res; scanf("%d", &res);
    return res;
}

int r1, r2;
ii a, b, c;

ii Get(int res)
{
    for (int i = 0; i < 6; i++)
        for (int j = i + 1; j < 6; j++)
            if (nums[i] * nums[j] == res) return ii(nums[i], nums[j]);
}

int main()
{
    int all = 1;
    for (int i = 0; i < 6; i++)
        all *= nums[i];
    r1 = Get(1, 2); a = Get(r1);
    r2 = Get(3, 4); b = Get(r2);
    c = Get(all / r1 / r2);
    int tmp = Get(1, 3);
    if (a.first * b.first != tmp && a.first * b.second != tmp) swap(a.first, a.second);
    if (a.first * b.first != tmp) swap(b.first, b.second);
    tmp = Get(1, 5);
    if (a.first * c.first != tmp) swap(c.first, c.second);
    printf("! %d %d %d %d %d %d\n", a.first, a.second, b.first, b.second, c.first, c.second);
    fflush(stdout);
    return 0;
}