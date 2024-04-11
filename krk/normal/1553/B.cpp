#include <bits/stdc++.h>
using namespace std;

const int Maxn = 505;

int T;
char A[Maxn];
char B[2 * Maxn];
int alen, blen;

bool Check(int pos, int right, int left)
{
    int pnt = 0;
    if (A[pos] != B[pnt++]) return false;
    for (int i = 0; i < right; i++) {
        if (++pos >= alen || pnt >= blen) return false;
        if (A[pos] != B[pnt++]) return false;
    }
    for (int i = 0; i < left; i++) {
        if (--pos < 0 || pnt >= blen) return false;
        if (A[pos] != B[pnt++]) return false;
    }
    return pnt == blen;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%s", A);
        scanf("%s", B);
        alen = strlen(A);
        blen = strlen(B);
        bool ok = false;
        for (int i = 0; i < alen && !ok; i++)
            for (int j = 0; j < alen && !ok; j++)
                for (int k = 0; k < alen && !ok; k++)
                    ok = Check(i, j, k);
        printf("%s\n", ok? "YES": "NO"); 
    }
    return 0;
}