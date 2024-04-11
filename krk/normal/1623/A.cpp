#include <bits/stdc++.h>
using namespace std;

int T;
int n, m, rb, cb, rd, cd;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d %d %d %d", &n, &m, &rb, &cb, &rd, &cd);
        int res1 = rb <= rd? rd - rb: n - rb + n - rd;
        int res2 = cb <= cd? cd - cb: m - cb + m - cd;
        printf("%d\n", min(res1, res2));
    }
    return 0;
}