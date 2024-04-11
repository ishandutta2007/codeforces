#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;

const int Maxn = 400005;
const int Maxb = 26;

int n;
int cur;
ii my[2][2][Maxn];
int slen[2][2];
int res;

ll getSame(int b, ii A[], int alen)
{
    int r = alen;
    ll res = 0;
    for (int i = 0; i < alen; i++) {
        while (r > 0 && A[i].first + A[r - 1].first >= 1 << b) r--;
        if (r <= i) res += alen - 1 - i;
        else res += alen - r;
    }
    return res;
}

ll getDif(int b, ii A[], int alen, ii B[], int blen)
{
    ll res = 0;
    int r = alen - 1;
    for (int i = 0; i < blen; i++) {
        while (r >= 0 && A[r].first + B[i].first >= 1 << b) r--;
        res += r + 1;
    }
    return res;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int a; scanf("%d", &a);
        my[cur][a & 1][slen[cur][a & 1]++] = ii(0, a);
    }
    for (int b = 0; b < Maxb; b++) {
        ll all = getSame(b, my[cur][0], slen[cur][0]) +
                 getSame(b, my[cur][1], slen[cur][1]) +
                 getDif(b, my[cur][0], slen[cur][0], my[cur][1], slen[cur][1]);
        if (all & 1) res |= 1 << b;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < slen[cur][i]; j++) {
                int fir = my[cur][i][j].first | (i << b);
                int sec = my[cur][i][j].second;
                int nxt = bool(my[cur][i][j].second & (1 << b + 1));
                my[!cur][nxt][slen[!cur][nxt]++] = ii(fir, sec);
            }
            slen[cur][i] = 0;
        }
        cur = !cur;
    }
    printf("%d\n", res);
    return 0;
}