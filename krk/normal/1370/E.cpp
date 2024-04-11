#include <bits/stdc++.h>
using namespace std;

const int Maxl = 1000005;

int n;
char A[Maxl], B[Maxl];
int st, mx, mn;

int main()
{
    scanf("%d", &n);
    scanf("%s", A);
    scanf("%s", B);
    for (int i = 0; i < n; i++)
        if (A[i] == '0' && B[i] == '1') {
            st++;
            mx = max(mx, st);
        } else if (A[i] == '1' && B[i] == '0') {
            st--;
            mn = min(mn, st);
        }
    printf("%d\n", st == 0? mx - mn: -1);
    return 0;
}