#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;
const int Maxm = 200005;

bool sq[Maxm];
int T;
int n;
int res[Maxn];

void Solve(int n)
{
    for (int i = n - 1; i >= 0; i--) if (sq[n - 1 + i]) {
        for (int j = i; j < n; j++)
            res[j] = n - 1 + i - j;
        Solve(i);
        break;
    }
}

int main()
{
    for (int i = 0; i * i < Maxm; i++)
        sq[i * i] = true;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        Solve(n);
        for (int i = 0; i < n; i++)
            printf("%d%c", res[i], i + 1 < n? ' ': '\n');
    }
    return 0;
}