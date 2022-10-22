#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;

int n;
int a[Maxn];
int mx = -1, best;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0, j; i < n; i = j) {
        j = i;
        while (j < n && a[i] == a[j]) j++;
        if (a[i] > mx || mx == a[i] && j - i > best) {
            mx = a[i]; best = j - i;
        }
    }
    printf("%d\n", best);
    return 0;
}