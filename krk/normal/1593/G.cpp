#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1000006;

int T;
char str[Maxn];
int even[Maxn], odd[Maxn];
int n;
int q;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%s", str + 1);
        n = strlen(str + 1);
        for (int i = 1; i <= n; i++) {
            even[i] = even[i - 1] + int(i % 2 == 0 && (str[i] == '[' || str[i] == ']'));
            odd[i] = odd[i - 1] + int(i % 2 == 1 && (str[i] == '[' || str[i] == ']'));
        }
        scanf("%d", &q);
        while (q--) {
            int l, r; scanf("%d %d", &l, &r);
            int ev = even[r] - even[l - 1];
            int od = odd[r] - odd[l - 1];
            printf("%d\n", abs(ev - od));
        }
    }
    return 0;
}