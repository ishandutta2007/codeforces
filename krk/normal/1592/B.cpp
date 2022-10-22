#include <bits/stdc++.h>
using namespace std;

int T;
int n, x;
vector <int> A, B;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &x);
        A.resize(n);
        for (int i = 0; i < n; i++)
            scanf("%d", &A[i]);
        B = A;
        sort(B.begin(), B.end());
        bool ok = true;
        for (int i = 0; i < A.size() && ok; i++)
            ok = A[i] == B[i] || i - x >= 0 || i + x < n;
        printf("%s\n", ok? "YES": "NO");
    }
    return 0;
}