#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;

int T;
int n;
int a[Maxn];

bool Check()
{
    int i = 1;
    while (i < n && a[i - 1] <= a[i]) i++;
    while (i < n && a[i - 1] >= a[i]) i++;
    return i >= n;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        printf("%s\n", Check()? "YES": "NO");
    }
    return 0;
}