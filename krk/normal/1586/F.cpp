#include <bits/stdc++.h>
using namespace std;

int n, k;

int Digs(int val)
{
    int res = 0;
    while (val) {
        res++;
        val /= k;
    }
    return res;
}

int Get(int a, int b)
{
    int cur = 0;
    while (true) {
        cur++;
        if (a % k < b % k) return cur;
        a /= k;
        b /= k;
    }
    return cur;
}

int main()
{
    scanf("%d %d", &n, &k);
    printf("%d\n", Digs(n - 1));
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            printf("%d%c", Get(i, j), i == n - 2 && j == n - 1? '\n': ' ');
    return 0;
}