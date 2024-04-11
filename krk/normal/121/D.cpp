#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 100005;
const ll lim = 100000000000000000ll;
const ll bInf = 4000000000000000000ll;
const int Maxm = 530000;

int n;
ll k;
ll lef[Maxn], rig[Maxn];
vector <ll> seq;
ll Lsum[Maxm], Rsum[Maxm];
int Lcnt[Maxm], Rcnt[Maxm];
int res;

int main()
{
    seq.push_back(4);
    seq.push_back(7);
    for (int i = 0; i < seq.size() && seq[i] <= lim; i++) {
        seq.push_back(10ll * seq[i] + 4);
        seq.push_back(10ll * seq[i] + 7);
    }
    scanf("%d %I64d", &n, &k);
    ll mn = bInf;
    for (int i = 0; i < n; i++) {
        scanf("%I64d %I64d", &lef[i], &rig[i]);
        mn = min(mn, rig[i] - lef[i]);
        int ind = upper_bound(seq.begin(), seq.end(), lef[i]) - seq.begin() - 1;
        if (ind >= 0) { Lsum[ind] = min(bInf, Lsum[ind] + lef[i] - seq[ind]); Lcnt[ind]++; }
        ind = lower_bound(seq.begin(), seq.end(), rig[i]) - seq.begin();
        if (ind < seq.size()) { Rsum[ind] = min(bInf, Rsum[ind] + seq[ind] - rig[i]); Rcnt[ind]++; }
    }
    for (int i = int(seq.size()) - 2; i >= 0; i--) {
        Lsum[i] = min(bInf, Lsum[i] + Lsum[i + 1]);
        Lcnt[i] += Lcnt[i + 1];
        if (Lcnt[i + 1] > 0)
            if (seq[i + 1] - seq[i] <= bInf / Lcnt[i + 1])
                Lsum[i] = min(bInf, Lsum[i] + ll(seq[i + 1] - seq[i]) * Lcnt[i + 1]);
            else Lsum[i] = bInf;
    }
    for (int i = 1; i < seq.size(); i++) {
        Rsum[i] = min(bInf, Rsum[i] + Rsum[i - 1]);
        Rcnt[i] += Rcnt[i - 1];
        if (Rcnt[i - 1] > 0)
            if (seq[i] - seq[i - 1] <= bInf / Rcnt[i - 1])
                Rsum[i] = min(bInf, Rsum[i] + ll(seq[i] - seq[i - 1]) * Rcnt[i - 1]);
            else Rsum[i] = bInf;
    }
    for (int i = 0; i < seq.size(); i++) {
        int lef = i, rig = int(seq.size()) - 1;
        while (lef <= rig) {
            int mid = lef + rig >> 1;
            if (seq[mid] - seq[i] <= mn && Lsum[i] + Rsum[mid] <= k)
                lef = mid + 1;
            else rig = mid - 1;
        }
        res = max(res, rig - i + 1);
    }
    printf("%d\n", res);
    return 0;
}