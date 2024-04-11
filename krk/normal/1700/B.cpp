#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;

int T;
int n;
char str[Maxn];
char res[Maxn];

void Solve(int x)
{
    res[n] = '\0';
    int car = 0;
    for (int i = n - 1; i >= 0; i--) {
        car = str[i] - '0' + car;
        int nd = (x - car + 10) % 10;
        car += nd;
        res[i] = nd + '0';
        car /= 10;
    }
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        scanf("%s", str);
        Solve(1);
        if (res[0] == '0') Solve(2);
        printf("%s\n", res);
    }
    return 0;
}