#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int n, q;
deque <int> D;
int a[Maxn], b[Maxn];

int main()
{
    scanf("%d %d", &n, &q);
    for (int i = 0; i < n; i++) {
        int a; scanf("%d", &a);
        D.push_back(a);
    }
    for (int i = 1; i <= 2 * n; i++) {
        int A = D.front(); D.pop_front();
        int B = D.front(); D.pop_front();
        a[i] = A; b[i] = B;
        if (A < B) swap(A, B);
        D.push_front(A);
        D.push_back(B);
    }
    while (q--) {
        long long ind; scanf("%I64d", &ind);
        if (ind > 2 * n)
            ind = (ind - n) % (n - 1) + n;
        printf("%d %d\n", a[ind], b[ind]);
    }
    return 0;
}