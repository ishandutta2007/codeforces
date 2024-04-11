#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;

int n;
ll t;
ll a[Maxn], b[Maxn];
int num[Maxn];

int main()
{
    scanf("%d %I64d", &n, &t);
    for (int i = 0; i < n; i++)
        scanf("%I64d", &a[i]);
    for (int i = 0; i < n; i++)
        scanf("%d", &num[i]);
    for (int i = 0; i + 1 < n; i++)
        if (num[i] > num[i + 1]) { printf("No\n"); return 0; }
    ll lst = a[0];
    for (int i = 0, j; i < n; i = j) {
        j = i;
        int got = num[i];
        if (got <= i) { printf("No\n"); return 0; }
        int mx = got;
        while (j < got) {
            mx = max(mx, num[j]);
            j++;
        }
        if (mx != got) { printf("No\n"); return 0; }
        for (int l = i; l + 1 < j; l++) {
            lst = max(lst, a[l + 1] + t);
            b[l] = lst++;
        }
        lst = max(lst, a[j - 1] + t);
        b[j - 1] = lst++;
    }
    for (int i = 0; i < n; i++)
        if (num[i] < n && a[num[i]] + t <= b[i]) {
            printf("No\n"); return 0;
        }
    printf("Yes\n");
    for (int i = 0; i < n; i++)
        printf("%I64d%c", b[i], i + 1 < n? ' ': '\n');
    return 0;
}