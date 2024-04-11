#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;
const int Maxk = 22;

int n;
int a[Maxn];
int B[Maxk], my[Maxk];

bool Check(int k)
{
    fill(B, B + Maxk, 0); fill(my, my + Maxk, 0);
    for (int i = 0; i < n; i++) if (a[i] < 1 << k) {
        int num = a[i];
        for (int j = Maxk - 1; j >= 0; j--)
            if (num & 1 << j)
                if (B[j]) num ^= B[j];
                else { B[j] = num; my[j] = a[i]; break; }
    }
    for (int i = 0; i < k; i++)
        if (!my[i]) return false;
    return true;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    int k = Maxk - 1;
    while (!Check(k)) k--;
    printf("%d\n", k);
    for (int i = 0; i < 1 << k; i++) {
        int gray = (i ^ (i >> 1));
        int res = 0;
        for (int j = 0; j < k; j++)
            if (gray & 1 << j) res ^= my[j];
        printf("%d%c", res, i + 1 < (1 << k)? ' ': '\n');
    }
    return 0;
}