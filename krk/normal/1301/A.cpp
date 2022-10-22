#include <bits/stdc++.h>
using namespace std;

int T;
string A, B, C;

int main()
{
    cin >> T;
    while (T--) {
        cin >> A;
        cin >> B;
        cin >> C;
        bool ok = true;
        for (int i = 0; i < A.length() && ok; i++)
            ok = A[i] == C[i] || B[i] == C[i];
        printf("%s\n", ok? "YES": "NO");
    }
    return 0;
}