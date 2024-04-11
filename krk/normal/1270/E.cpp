#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <ll, int> lli;

const int Maxn = 1005;

int n;
int X[Maxn], Y[Maxn];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d %d", &X[i], &Y[i]);
    while (true) {
        vector <int> A, B;
        for (int i = 0; i < n; i++)
            if (X[i] % 2 == 0 && Y[i] % 2 == 0 || X[i] % 2 != 0 && Y[i] % 2 != 0)
                A.push_back(i);
            else B.push_back(i);
        if (A.size() != n && B.size() != n) {
            printf("%d\n", int(A.size()));
            for (int i = 0; i < A.size(); i++)
                printf("%d%c", A[i] + 1, i + 1 < A.size()? ' ': '\n');
            return 0;
        }
        A.clear(); B.clear();
        for (int i = 0; i < n; i++)
            if (X[i] % 2 == 0) A.push_back(i);
            else B.push_back(i);
        if (A.size() != n && B.size() != n) {
            printf("%d\n", int(A.size()));
            for (int i = 0; i < A.size(); i++)
                printf("%d%c", A[i] + 1, i + 1 < A.size()? ' ': '\n');
            return 0;
        }
        for (int i = 0; i < n; i++) {
            if (X[i] % 2 != 0) X[i]--;
            X[i] /= 2;
            if (Y[i] % 2 != 0) Y[i]--;
            Y[i] /= 2;
        }
    }
    return 0;
}