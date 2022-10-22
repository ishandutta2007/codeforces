#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;

const int Maxn = 1000005;
const int Maxm = 500001;

int n;
int cnt[Maxn];
ii my[Maxn];
int seq[Maxn];
int slen;
ii mx[Maxn][2];
ll res;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int a; scanf("%d", &a);
        cnt[a]++;
    }
    my[0] = ii(-1, -1);
    for (int i = 1; i < Maxn; i++) {
        if (cnt[i] == 0) my[i] = my[i - 1];
        else if (cnt[i] == 1) my[i] = ii(my[i - 1].second, i);
        else my[i] = ii(i, i);
        cnt[i] += cnt[i - 1];
    }
    for (int y = 2; y < Maxm; y++) {
        ll all = 0;
        slen = 0;
        for (int j = 0; j + y <= Maxn; j += y) {
            const ii &p = my[j + y - 1];
            if (p.first >= j) seq[slen++] = p.first;
            if (p.second >= j) seq[slen++] = p.second;
            int add = cnt[j + y - 1];
            if (j) add -= cnt[j - 1];
            all += ll(j / y) * add;
        }
        mx[slen][0] = mx[slen][1] = ii(0, 0);
        for (int i = slen - 1; i >= 0; i--) {
            ii g = ii(seq[i] % y, seq[i]);
            mx[i][0] = mx[i + 1][0];
            mx[i][1] = mx[i + 1][1];
            if (g > mx[i][0]) mx[i][1] = mx[i][0], mx[i][0] = g;
            else if (g > mx[i][1]) mx[i][1] = g;
        }
        int lef = 2, rig = Maxm - 1;
        while (lef <= rig) {
            int x = lef + rig >> 1;
            int ind = lower_bound(seq, seq + slen, x) - seq;
            ll best = 0;
            if (mx[ind][0].second >= 2 * x) {
                ll cur = all - mx[ind][0].second / y + (mx[ind][0].second - 2 * x) / y;
                best = max(best, cur);
            }
            if (mx[ind][0].second >= x && mx[ind][1].second >= x) {
                ll cur = all - mx[ind][0].second / y + (mx[ind][0].second - x) / y
                             - mx[ind][1].second / y + (mx[ind][1].second - x) / y;
                best = max(best, cur);
            }
            if (best >= x) {
                res = max(res, ll(x) * y);
                lef = x + 1;
            } else rig = x - 1;
        }
    }
    cout << res << endl;
    return 0;
}