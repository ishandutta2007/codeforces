#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;

int T;
int n;
char str[Maxn];
char A[Maxn], B[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n); scanf("%s", str);
        bool was = false;
        for (int i = 0; i < n; i++)
            if (str[i] == '2')
                if (!was) A[i] = B[i] = '1';
                else A[i] = '2', B[i] = '0';
            else if (str[i] == '1')
                if (!was) A[i] = '0', B[i] = '1', was = true;
                else A[i] = '1', B[i] = '0';
            else A[i] = B[i] = '0';
        A[n] = B[n] = '\0';
        printf("%s\n%s\n", A, B);
    }
    return 0;
}