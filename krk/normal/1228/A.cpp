#include <bits/stdc++.h>
using namespace std;

int l, r;

bool Ok(int num)
{
    int mask = 0;
    while (num) {
        if (mask & 1 << num % 10)
            return false;
        mask |= 1 << num % 10;
        num /= 10;
    }
    return true;
}

int main()
{
    cin >> l >> r;
    for (int i = l; i <= r; i++)
        if (Ok(i)) { printf("%d\n", i); return 0; }
    printf("-1\n");
    return 0;
}