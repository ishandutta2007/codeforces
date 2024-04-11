#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 1005;

int T;
int n;
int L[Maxn], R[Maxn];
set <ii> S;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        S.clear();
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &L[i], &R[i]);
            S.insert(ii(L[i], R[i]));
        }
        for (int i = 0; i < n; i++)
            for (int j = L[i]; j <= R[i]; j++)
                if ((j == L[i] || S.count(ii(L[i], j - 1))) && (j == R[i] || S.count(ii(j + 1, R[i])))) {
                    printf("%d %d %d\n", L[i], R[i], j);
                    break;
                }
    }
    return 0;
}