#include <bits/stdc++.h>
using namespace std;

int T;
int n, m, k;
string A;
string B;

int main()
{
    cin >> T;
    while (T--) {
        cin >> n >> m >> k;
        cin >> A;
        cin >> B;
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        int i = 0, j = 0;
        string C;
        int st = 0;
        while (i < n && j < m)
            if (A[i] < B[j] && st < k || st == -k) {
                C += A[i++];
                st = max(st + 1, 1);
            } else {
                C += B[j++];
                st = min(st - 1, -1);
            }
        cout << C << endl;
    }
    return 0;
}