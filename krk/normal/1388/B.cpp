#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;

int T;
int n;
char res[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        fill(res, res + n, '9');
        res[n] = '\0';
        int delt = (n - 1) / 4 + 1;
        for (int i = 1; i <= delt; i++)
            res[n - i] = '8';
        printf("%s\n", res);
    }
    return 0;
}