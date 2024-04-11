#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;

int n, q;
char str[Maxn];
int res;

int Get(int ind)
{
    if (ind < 0 || ind + 3 > n + 1) return 0;
    return int(str[ind] == 'a' && str[ind + 1] == 'b' && str[ind + 2] == 'c');
}

int main()
{
    scanf("%d %d", &n, &q);
    scanf("%s", str + 1);
    for (int i = 1; i <= n; i++)
        res += Get(i);
    while (q--) {
        int ind; char ch; scanf("%d %c", &ind, &ch);
        for (int i = ind - 2; i <= ind; i++)
            res -= Get(i);
        str[ind] = ch;
        for (int i = ind - 2; i <= ind; i++)
            res += Get(i);
        printf("%d\n", res);
    }
    return 0;
}