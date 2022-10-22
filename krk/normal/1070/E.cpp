#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int Maxn = 200005;
const int Maxm = 1048576;

int c;
int n, m;
ll t;
int a[Maxn];
int cnt[Maxm];
ll sum[Maxm];

void Clear(int v, int l, int r)
{
    cnt[v] = sum[v] = 0;
    if (l < r) {
        int m = l + r >> 1;
        Clear(2 * v, l, m);
        Clear(2 * v + 1, m + 1, r);
    }
}

void Update(int v, int l, int r, int ind, int mult)
{
    cnt[v] += mult; sum[v] += mult * a[ind];
    if (l < r) {
        int m = l + r >> 1;
        if (ind <= m) Update(2 * v, l, m, ind, mult);
        else Update(2 * v + 1, m + 1, r, ind, mult);
    }
}

ll getSum(int v, int l, int r, int mycnt)
{
    if (mycnt <= 0) return 0;
    if (mycnt >= cnt[v]) return sum[v];
    if (l < r) {
        int m = l + r >> 1;
        ll res = getSum(2 * v, l, m, mycnt);
        res += getSum(2 * v + 1, m + 1, r, mycnt - cnt[2 * v]);
        return res;
    }
}

int main()
{
    scanf("%d", &c);
    while (c--) {
        scanf("%d %d %I64d", &n, &m, &t);
        vector <ii> seq;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            seq.push_back(ii(a[i], i));
        }
        Clear(1, 0, n - 1);
        sort(seq.begin(), seq.end());
        int res = 0, bestd = 1;
        priority_queue <int> Q;
        for (int i = 0, j; i < seq.size(); i = j) {
            j = i;
            while (j < seq.size() && seq[i].first == seq[j].first) {
                int ind = seq[j].second;
                Update(1, 0, n - 1, ind, 1);
                Q.push(ind);
                j++;
            }
            while (!Q.empty()) {
                int ind = Q.top();
                int breaks = (int(Q.size()) - 1) / m * m;
                if (getSum(1, 0, n - 1, Q.size()) + getSum(1, 0, n - 1, breaks) > t) {
                    Update(1, 0, n - 1, ind, -1);
                    Q.pop();
                } else break;
            }
            if (Q.size() > res) {
                res = Q.size();
                bestd = seq[i].first;
            }
        }
        printf("%d %d\n", res, bestd);
    }
    return 0;
}