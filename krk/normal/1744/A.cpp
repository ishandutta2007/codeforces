#include <bits/stdc++.h>
using namespace std;

const int Maxn = 52;

int T;
int n;
int a[Maxn];
char str[Maxn];

bool Solve()
{
    map <int, char> M;
    for (int i = 0; i < n; i++)
        if (M.count(a[i])) {
            if (str[i] != M[a[i]])
                return false;
        } else M[a[i]] = str[i];
    return true;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        scanf("%s", str);
        printf("%s\n", Solve()? "YES": "NO");
    }
    return 0;
}