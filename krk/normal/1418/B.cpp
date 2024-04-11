#include <bits/stdc++.h>
using namespace std;

const int Maxn = 105;

int T;
int n;
int a[Maxn];
int l[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        vector <int> seq;
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &l[i]);
            if (l[i] == 0) seq.push_back(a[i]);
        }
        sort(seq.rbegin(), seq.rend());
        for (int i = n; i >= 1; i--)
            if (l[i] == 0) {
                a[i] = seq.back();
                seq.pop_back();
            }
        for (int i = 1; i <= n; i++)
            printf("%d%c", a[i], i + 1 <= n? ' ': '\n');
    }
    return 0;
}