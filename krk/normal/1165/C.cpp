#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int n;
char A[Maxn], B[Maxn];
int slen;

int main()
{
    cin >> n;
    scanf("%s", A);
    for (int i = 0; i < n; i++)
        if (slen % 2 == 0 || B[slen - 1] != A[i]) B[slen++] = A[i];
    if (slen % 2) slen--;
    B[slen] = '\0';
    printf("%d\n", n - slen);
    printf("%s\n", B);
    return 0;
}