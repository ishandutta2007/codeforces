#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;
const int Maxm = 20;

int n;
int a[Maxn];
int b[Maxn];
int mx[Maxn][Maxm], mn[Maxn][Maxm];
int res[Maxn];

int getMax(int ind, int val)
{
    for (int i = Maxm - 1; i >= 0; i--) if (ind + (1 << i) <= 2 * n && mx[ind][i] <= val)
        ind += 1 << i;
    return ind;
}

int getMin(int ind, int val)
{
    for (int i = Maxm - 1; i >= 0; i--) if (ind + (1 << i) <= 2 * n && 2 * mn[ind][i] >= val)
        ind += 1 << i;
    return ind;
}

int main()
{
    scanf("%d", &n);
    int bi = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if (a[i] > a[bi]) bi = i;
    }
    for (int i = 0; i < 2 * n; i++) {
        b[i] = a[(bi + i) % n];
        mn[i][0] = mx[i][0] = b[i];
    }
    for (int j = 1; 1 << j <= 2 * n; j++)
        for (int i = 0; i + (1 << j) <= 2 * n; i++) {
            int ni = i + (1 << j - 1);
            mn[i][j] = min(mn[i][j - 1], mn[ni][j - 1]);
            mx[i][j] = max(mx[i][j - 1], mx[ni][j - 1]);
        }
    if (getMin(n, b[n]) >= 2 * n) {
        for (int i = 0; i < n; i++)
            printf("-1%c", i + 1 < n? ' ': '\n');
        return 0;
    }
    res[n] = getMin(n, b[n]) - n;
    for (int i = n - 1; i >= 0; i--) {
        int mymx = getMax(i, b[i]);
        int mymn = getMin(i, b[i]);
        if (mymn < mymx) res[i] = mymn - i;
        else res[i] = mymx - i + res[mymx];
    }
    for (int i = 0; i < n; i++) {
        int ind = (i - bi + n) % n;
        printf("%d%c", res[ind], i + 1 < n? ' ': '\n');
    }
    return 0;
}