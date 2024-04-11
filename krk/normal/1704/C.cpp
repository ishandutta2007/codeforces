#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;

int T;
int n, m;
int a[Maxn];
vector <int> seq;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        for (int i = 0; i < m; i++) {
            scanf("%d", &a[i]);
            a[i]--;
        }
        sort(a, a + m);
        seq.clear();
        for (int i = 0; i + 1 < m; i++)
            seq.push_back(a[i + 1] - a[i] - 1);
        seq.push_back(a[0] + n - a[m - 1] - 1);
        sort(seq.rbegin(), seq.rend());
        int res = 0;
        for (int i = 0; i < seq.size(); i++) {
            int cur = seq[i] - 4 * i;
            if (cur <= 0) break;
            res += max(1, cur - 1);
        }
        printf("%d\n", n - res);
    }
    return 0;
}