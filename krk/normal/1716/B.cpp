#include <bits/stdc++.h>
using namespace std;

const int Maxn = 105;

int T;
int n;
int a[Maxn];

void Print()
{
    for (int i = 1; i <= n; i++)
        printf("%d%c", a[i], i + 1 <= n? ' ': '\n');
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            a[i] = i;
        printf("%d\n", n);
        Print();
        for (int i = 2; i <= n; i++) {
            swap(a[i - 1], a[i]);
            Print();
        }
    }
    return 0;
}