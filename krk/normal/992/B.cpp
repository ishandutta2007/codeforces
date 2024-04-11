#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

int l, r, x, y;
vector <ii> seq;
int res;

void Gen(int lvl, int a, int b)
{
    if (lvl >= seq.size()) {
        if (l <= a && a <= r && l <= b && b <= r) res++;
    } else {
        Gen(lvl + 1, a * seq[lvl].first, b * seq[lvl].second);
        if (seq[lvl].first != seq[lvl].second)
            Gen(lvl + 1, a * seq[lvl].second, b * seq[lvl].first);
    }
}

int main()
{
    scanf("%d %d %d %d", &l, &r, &x, &y);
    if (y % x != 0) { printf("0\n"); return 0; }
    for (int i = 2; i * i <= y; i++) if (y % i == 0) {
        int cnt2 = 1;
        while (y % i == 0) { cnt2 *= i; y /= i; }
        int cnt1 = 1;
        while (x % i == 0) { cnt1 *= i; x /= i; }
        seq.push_back(ii(cnt1, cnt2));
    }
    if (y > 1) {
        int cnt1 = 1;
        while (x % y == 0) { cnt1 *= y; x /= y; }
        seq.push_back(ii(cnt1, y));
    }
    Gen(0, 1, 1);
    printf("%d\n", res);
    return 0;
}