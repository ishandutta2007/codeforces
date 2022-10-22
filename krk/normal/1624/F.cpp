#include <bits/stdc++.h>
using namespace std;

int n;

int Quer(int x)
{
    printf("+ %d\n", x); fflush(stdout);
    int res; scanf("%d", &res);
    return res;
}

int main()
{
    scanf("%d", &n);
    int lef = 1, rig = n - 1;
    int lst = 0;
    while (lef <= rig) {
        int mid = lef + rig >> 1;
        int add = (lst + 1) * n - 1 - mid;
        int got = Quer(add);
        if (got != lst) {
            lef = mid + 1 + add;
            rig += add;
            lst = got;
        } else {
            lef += add;
            rig = mid - 1 + add;
        }
    }
    printf("! %d\n", lef); fflush(stdout);
    return 0;
}