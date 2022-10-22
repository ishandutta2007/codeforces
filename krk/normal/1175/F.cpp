#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int Maxn = 300005;

int n;
int a[Maxn];
int my[Maxn], mx[Maxn];
vector <int> req[Maxn];
ll res;

void Solve(int l, int r)
{
    if (l == r) res += a[l] == 1;
    else {
        int m = l + r >> 1;
        Solve(l, m);
        Solve(m + 1, r);
        for (int i = l; i <= r; i++) {
            my[a[i]] = 0;
            req[i].clear();
        }
        my[a[m + 1]] = m + 1; mx[m + 1] = a[m + 1];
        int nd = m + 2 - a[m + 1];
        if (l <= nd && nd <= m) req[nd].push_back(m + 1);
        int pnt = m + 2;
        while (pnt <= r && !my[a[pnt]]) {
            my[a[pnt]] = pnt;
            mx[pnt] = max(mx[pnt - 1], a[pnt]);
            int nd = pnt + 1 - mx[pnt];
            if (l <= nd && nd <= m) req[nd].push_back(pnt);
            pnt++;
        }
        pnt--;
        int curmx = 0;
        for (int i = m; i >= l && pnt > m; i--) {
            curmx = max(curmx, a[i]);
            if (my[a[i]]) pnt = min(pnt, my[a[i]] - 1);
            if (pnt <= m) break;
            my[a[i]] = i;
            int nd = i - 1 + curmx;
            if (m + 1 <= nd && nd <= pnt && mx[nd] < curmx) res++;
            for (int j = 0; j < req[i].size(); j++) {
                int ind = req[i][j];
                if (ind <= pnt && curmx < mx[ind]) res++;
            }
        }
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    Solve(1, n);
    cout << res << endl;
    return 0;
}