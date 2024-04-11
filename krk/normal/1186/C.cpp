#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1000005;

char A[Maxn], B[Maxn];
int alen, blen;
int res;

int main()
{
    scanf("%s", A); alen = strlen(A);
    scanf("%s", B); blen = strlen(B);
    int sub = 0;
    for (int i = 0; i < blen; i++)
        sub += B[i] == '1';
    int cur = 0;
    for (int i = 0; i < blen - 1; i++)
        cur += A[i] == '1';
    for (int i = blen - 1; i < alen; i++) {
        cur += A[i] == '1';
        res += cur % 2 == sub % 2;
        cur -= A[i - blen + 1] == '1';
    }
    printf("%d\n", res);
    return 0;
}