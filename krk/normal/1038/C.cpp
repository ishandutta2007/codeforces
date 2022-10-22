#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 1000005;

int n;
vector <int> A, B;
ll res;

int main()
{
    scanf("%d", &n);
    A.resize(n); B.resize(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &A[i]);
    for (int i = 0; i < n; i++)
        scanf("%d", &B[i]);
    sort(A.rbegin(), A.rend());
    sort(B.rbegin(), B.rend());
    bool fir = true;
    int i = 0, j = 0;
    while (i < A.size() || j < B.size()) {
        if (fir)
            if (i < A.size() && (j >= B.size() || A[i] >= B[j])) {
                res += A[i]; i++;
            } else j++;
        else if (j < B.size() && (i >= A.size() || B[j] >= A[i])) {
            res -= B[j]; j++;
        } else i++;
        fir = !fir;
    }
    cout << res << endl;
    return 0;
}