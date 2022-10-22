#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;

int T;
int n;
char A[Maxn];
char B[Maxn];

ll Solve()
{
    int i = 0, j = 0;
    ll st = 0, res = 0;
    while (i < n || j < n)
        if (i >= n || j >= n || A[i] != B[j])
            return -1;
        else {
            char nd = A[i];
            while (i < n && A[i] == nd) {
                st++; i++;
            }
            while (j < n && B[j] == nd) {
                st--; j++;
            }
            res += abs(st);
        }
    return res;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        scanf("%s", A);
        scanf("%s", B);
        printf("%I64d\n", Solve());
    }
    return 0;
}