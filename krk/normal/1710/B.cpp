#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll Inf = 4000000000000000000ll;
const int Maxn = 200005;

int T;
int n, m;
int x[Maxn], p[Maxn];
ll add1[Maxn], cnt1[Maxn];
ll add2[Maxn], cnt2[Maxn];
ll tot[Maxn];
ll mx[Maxn];
char res[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        vector <int> un;
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &x[i], &p[i]);
            un.push_back(x[i]);
        }
        sort(un.begin(), un.end()); un.erase(unique(un.begin(), un.end()), un.end());
        for (int i = 0; i < un.size(); i++) {
            add1[i] = cnt1[i] = 0;
            add2[i] = cnt2[i] = 0;
            tot[i] = 0;
            mx[i] = -Inf;
        }
        for (int i = 0; i < n; i++) {
            int ind = lower_bound(un.begin(), un.end(), x[i]) - un.begin();
            int rig = lower_bound(un.begin(), un.end(), x[i] + p[i]) - un.begin();
            add1[ind] += p[i] + x[i];
            cnt1[ind]++;
            add1[rig] -= (p[i] + x[i]);
            cnt1[rig]--;
            int lef = upper_bound(un.begin(), un.end(), x[i] - p[i]) - un.begin();
            if (lef < ind) {
                add2[lef] += p[i] - x[i];
                cnt2[lef]++;
                add2[ind] -= (p[i] - x[i]);
                cnt2[ind]--;
            }
        }
        ll cur1 = 0, cur2 = 0;
        ll c1 = 0, c2 = 0;
        for (int i = 0; i < un.size(); i++) {
            cur1 += add1[i];
            cur2 += add2[i];
            c1 += cnt1[i];
            c2 += cnt2[i];
            tot[i] = cur1 - c1 * un[i] + cur2 + c2 * un[i];
        }
        ll cur = -Inf;
        for (int i = 0; i < un.size(); i++) {
            if (tot[i] > m) cur = max(cur, tot[i] - m - un[i]);
            mx[i] = max(mx[i], cur + un[i]);
        }
        cur = -Inf;
        for (int i = int(un.size()) - 1; i >= 0; i--) {
            if (tot[i] > m) cur = max(cur, tot[i] - m + un[i]);
            mx[i] = max(mx[i], cur - un[i]);
        }
        for (int i = 0; i < n; i++) {
            int ind = lower_bound(un.begin(), un.end(), x[i]) - un.begin();
            res[i] = '0' + int(p[i] >= mx[ind]);
        }
        res[n] = '\0';
        printf("%s\n", res);
    }
    return 0;
}