#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;
const int Maxm = 20;

int n;
int a[Maxn];
int G[Maxn][Maxm];

int gcd(int a, int b) { return a? gcd(b % a, a): b; }

int getG(int l, int r)
{
    int res = 0;
    for (int i = Maxm - 1; i >= 0; i--) if (l + (1 << i) <= r + 1) {
        res = gcd(res, G[l][i]);
        l += 1 << i;
    }
    return res;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        G[i][0] = a[i];
    }
    for (int j = 1; j < Maxm; j++)
        for (int i = 1; i + (1 << j) <= n + 1; i++)
            G[i][j] = gcd(G[i][j - 1], G[i + (1 << j - 1)][j - 1]);
    int lst = 0;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        int lef = lst + 1, rig = i;
        bool hit = false;
        while (lef <= rig) {
            int mid = lef + rig >> 1;
            int got = getG(mid, i);
            if (got == i - mid + 1) { hit = true; break; }
            else if (got < i - mid + 1) lef = mid + 1;
            else rig = mid - 1;
        }
        if (hit) { cnt++; lst = i; }
        printf("%d%c", cnt, i + 1 <= n? ' ': '\n');
    }
    return 0;
}