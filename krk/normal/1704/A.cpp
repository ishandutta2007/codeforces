#include <bits/stdc++.h>
using namespace std;

int T;
int n, m;
string A, B;

bool Solve()
{
    int pnt = 0;
    while (pnt < A.length() && A[pnt] != B[0]) pnt++;
    if (pnt >= A.length()) return false;
    pnt++;
    if (int(A.length()) - pnt < int(B.length()) - 1) return false;
    for (int i = 1; i <= int(B.length()) - 1; i++)
        if (A[int(A.size()) - i] != B[int(B.size()) - i])
            return false;
    return true;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        cin >> A;
        cin >> B;
        printf("%s\n", Solve()? "YES": "NO");
    }
    return 0;
}