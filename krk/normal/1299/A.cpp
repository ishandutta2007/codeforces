#include <bits/stdc++.h>
using namespace std;

const int Maxb = 30;
const int Maxn = 100005;

int cnt[Maxb];
int n;
int a[Maxn];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        for (int j = 0; j < Maxb; j++)
            if (a[i] & 1 << j) cnt[j]++;
    }
    int best = -1, got = -1;
    for (int i = 0; i < n; i++) {
        int cand = 0;
        for (int j = 0; j < Maxb; j++)
            if (a[i] & 1 << j)
                if (cnt[j] == 1) cand |= 1 << j;
        if (cand > got) { got = cand; best = i; }
    }
    swap(a[0], a[best]);
    for (int i = 0; i < n; i++)
        printf("%d%c", a[i], i + 1 < n? ' ': '\n');
    return 0;
}