#include <bits/stdc++.h>
using namespace std;

int T;

bool Has(int x)
{
    printf("? 1 %d\n", x); fflush(stdout);
    set <int> S;
    for (int i = 0; i < x; i++) {
        int num; scanf("%d", &num);
        S.insert(num);
    }
    for (int i = 1; i <= x; i++)
        S.erase(i);
    return x % 2 != S.size() % 2;
}

void Answer(int x)
{
    printf("! %d\n", x); fflush(stdout);
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        int n; scanf("%d", &n);
        int l = 1, r = n - 1;
        while (l <= r) {
            int mid = l + r >> 1;
            if (Has(mid)) r = mid - 1;
            else l = mid + 1;
        }
        Answer(l);
    }
    return 0;
}