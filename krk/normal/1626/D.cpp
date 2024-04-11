#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int T;
int n;
int seq[Maxn];

int Get(int x)
{
    int p = 0;
    while (1 << p < x) p++;
    return 1 << p;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &seq[i]);
        sort(seq, seq + n);
        int res = Get(n) + Get(0) + Get(0);
        int lst = 0;
        for (int i = 0; i < n; i++) {
            if (seq[i] > lst) {
                int x = lst + 1;
                res = min(res, Get(i) + Get(n - i) + Get(0));
                for (int j = 0; j < 20; j++) {
                    int ind = max(i, n - (1 << j));
                    if (ind > 0 && seq[ind - 1] == seq[ind])
                        ind = upper_bound(seq, seq + n, seq[ind]) - seq;
                    res = min(res, Get(i) + Get(n - ind) + Get(ind - i));
                }
            }
            lst = seq[i];
        }
        printf("%d\n", res - n);
    }
    return 0;
}