#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int q;
int n, k;
int a[Maxn];
vector <int> seq;

int main()
{
    scanf("%d", &q);
    while (q--) {
        scanf("%d %d", &n, &k);
        seq.clear();
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            if (a[i] % 2) seq.push_back(i);
        }
        if (!seq.empty()) seq.back() = n;
        if (seq.size() % 2 == k % 2 && seq.size() >= k) {
            printf("YES\n");
            for (int i = 0; i < k - 1; i++)
                printf("%d ", seq[i]);
            printf("%d\n", n);
        } else printf("NO\n");
    }
    return 0;
}