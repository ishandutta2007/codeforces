#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 505;

int T;
int n;
int a[Maxn], b[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        multiset <int> A, B;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            A.insert(a[i]);
        }
        for (int i = 0; i < n; i++) {
            scanf("%d", &b[i]);
            B.insert(b[i]);
        }
        if (A != B) { printf("No\n"); continue; }
        if (n % 2 != 0 && a[n / 2] != b[n / 2]) { printf("No\n"); continue; }
        multiset <ii> pA, pB;
        for (int i = 0; i < n / 2; i++) {
            int fir = a[i], sec = a[n - 1 - i];
            if (fir > sec) swap(fir, sec);
            pA.insert(ii(fir, sec));
            fir = b[i], sec = b[n - 1 - i];
            if (fir > sec) swap(fir, sec);
            pB.insert(ii(fir, sec));
        }
        printf("%s\n", pA == pB? "Yes": "No");
    }
    return 0;
}