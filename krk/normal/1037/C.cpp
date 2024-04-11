#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1000005;

int n;
char A[Maxn], B[Maxn];
bool dif[Maxn];
int res;

int main()
{
    scanf("%d", &n);
    scanf("%s", A); scanf("%s", B);
    for (int i = 0; i + 1 < n; i++)
        if (A[i] != B[i] && A[i + 1] != B[i + 1] && A[i] != A[i + 1]) {
            swap(A[i], A[i + 1]); res++;
        }
    for (int i = 0; i < n; i++)
        if (A[i] != B[i]) res++;
    printf("%d\n", res);
    return 0;
}