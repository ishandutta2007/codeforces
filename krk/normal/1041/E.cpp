#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1005;

int n;
int was[Maxn];
int res[Maxn];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) {
        int a, b; scanf("%d %d", &a, &b);
        if (b != n) { printf("NO\n"); return 0; }
        was[a]++;
    }
    res[0] = n;
    int cur = 0;
    deque <int> seq;
    for (int i = n - 1; i > 0; i--)
        if (!was[i]) seq.push_back(i);
    for (int i = n - 1; i > 0; i--)
        if (was[i] > 0) {
            int st = cur + 1;
            cur += was[i];
            int en = cur - 1;
            res[cur] = i;
            if (st <= en) {
                if (seq.front() > i) { printf("NO\n"); return 0; }
                for (int j = st; j <= en; j++) {
                    res[j] = seq.front(); seq.pop_front();
                }
            }
        }
    printf("YES\n");
    for (int i = 0; i + 1 < n; i++)
        printf("%d %d\n", res[i], res[i + 1]);
    return 0;
}