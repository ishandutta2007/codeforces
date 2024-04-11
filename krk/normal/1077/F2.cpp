#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <ll, int> lli;

const int Maxn = 5005;

int n, k, x;
int a[Maxn];
lli seq[Maxn][Maxn];
int beg[Maxn], en[Maxn];

int main()
{
    scanf("%d %d %d", &n, &k, &x);
    seq[0][en[0]++] = lli(0, 0);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        for (int j = i - 1; j >= 0; j--) {
            while (beg[j] < en[j] && seq[j][beg[j]].second < i - k)
                beg[j]++;
            if (beg[j] < en[j]) {
                ll val = seq[j][beg[j]].first + ll(a[i]);
                int nj = j + 1;
                while (beg[nj] < en[nj] && seq[nj][en[nj] - 1].first <= val)
                    en[nj]--;
                seq[nj][en[nj]++] = lli(val, i);
            }
        }
    }
    while (beg[x] < en[x] && seq[x][beg[x]].second < n + 1 - k)
        beg[x]++;
    if (beg[x] < en[x])
        printf("%I64d\n", seq[x][beg[x]].first);
    else printf("-1\n");
    return 0;
}