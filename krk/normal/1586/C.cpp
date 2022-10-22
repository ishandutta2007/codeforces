#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1000005;

char str[Maxn];
int n, m;
string B[Maxn];
int sum[Maxn];

void Read(string &s)
{
    scanf("%s", str);
    s = str;
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        Read(B[i]);
    for (int j = 1; j < m; j++) {
        sum[j] = sum[j - 1];
        for (int i = 1; i < n; i++)
            if (B[i - 1][j] == 'X' && B[i][j - 1] == 'X')
                sum[j]++;
    }
    int q; scanf("%d", &q);
    while (q--) {
        int a, b; scanf("%d %d", &a, &b);
        a--; b--;
        printf("%s\n", sum[b] - sum[a] == 0? "YES": "NO");
    }
    return 0;
}