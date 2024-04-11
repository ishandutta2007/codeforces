#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1000005;

int n;
char str[Maxn];
int op, cl;
int L[Maxn], R[Maxn];
int res;

int main()
{
    scanf("%d", &n);
    scanf("%s", str);
    int cur = 0;
    for (int i = 0; i < n; i++) {
        if (str[i] == '(') {
            op++; cur++;
        } else { cl++; cur--; }
        L[i] = R[i] = cur;
    }
    if (abs(op - cl) != 2) {
        printf("0\n"); return 0;
    }
    for (int i = 1; i < n; i++)
        L[i] = min(L[i], L[i - 1]);
    for (int i = n - 2; i >= 0; i--)
        R[i] = min(R[i], R[i + 1]);
    if (op > cl) {
        for (int i = 0; i < n; i++) if (str[i] == '(') {
            if (i > 0 && L[i - 1] < 0) continue;
            if (R[i] - 2 < 0) continue;
            res++;
        }
    } else for (int i = 0; i < n; i++) if (str[i] == ')') {
        if (i > 0 && L[i - 1] < 0) continue;
        if (R[i] + 2 < 0) continue;
        res++;
    }
    printf("%d\n", res);
    return 0;
}