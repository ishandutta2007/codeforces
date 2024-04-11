#include <bits/stdc++.h>
using namespace std;

const int Maxn = 105;

int T;
int n;
int a[Maxn];

bool Prime(int x)
{
    if (x <= 1) return false;
    if (x == 2) return true;
    if (x % 2 == 0) return false;
    for (int i = 3; i * i <= x; i += 2)
        if (x % i == 0) return false;
    return true;
}

void Print(int ex)
{
    printf("%d\n", n - (ex != -1));
    bool was = false;
    for (int i = 1; i <= n; i++) if (i != ex) {
        if (was) printf(" ");
        else was = true;
        printf("%d", i);
    }
    printf("\n");
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            sum += a[i];
        }
        if (!Prime(sum)) Print(-1);
        else for (int i = 1; i <= n; i++) if (!Prime(sum - a[i])) {
            Print(i);
            break;
        }
    }
    return 0;
}