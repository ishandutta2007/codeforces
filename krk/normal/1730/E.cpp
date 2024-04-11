#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 500005;
const int Maxm = 1000005;

int T;
int n;
int a[Maxn];
int lef[Maxn], rig[Maxn];
int St[Maxn], slen;
vector <int> B[Maxm];
set <int> S;
int L[Maxn], R[Maxn];
ll res;

void Solve(const vector <int> &A, const vector <int> &B)
{
    int pnt = 0;
    for (auto el: A) {
        while (pnt < B.size() && B[pnt] < el) pnt++;
        if (pnt < B.size() && L[pnt] < el && B[pnt] < rig[el])
            res += ll(min(rig[el], R[pnt]) - B[pnt]) * (el - max(lef[el], L[pnt]));
        if (pnt > 0 && el < R[pnt - 1] && lef[el] < B[pnt - 1])
            res += ll(min(rig[el], R[pnt - 1]) - el) * (B[pnt - 1] - max(lef[el], L[pnt - 1]));
        if (pnt < B.size() && L[pnt] < el && B[pnt] < rig[el] &&
            pnt > 0 && el < R[pnt - 1] && lef[el] < B[pnt - 1])
            res -= ll(min(rig[el], R[pnt]) - B[pnt]) * (B[pnt - 1] - max(lef[el], L[pnt - 1]));
    }
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            B[a[i]].push_back(i);
            while (slen > 0 && a[St[slen - 1]] <= a[i]) {
                int ind = St[--slen];
                rig[ind] = i;
            }
            lef[i] = slen > 0? St[slen - 1]: 0;
            St[slen++] = i;
        }
        while (slen > 0)
            rig[St[--slen]] = n + 1;
        S.clear();
        S.insert(0);
        S.insert(n + 1);
        res = 0;
        for (int i = 0; i < Maxm; i++) {
            if (!B[i].empty()) {
                for (int j = 0; j < B[i].size(); j++) {
                    int ind = B[i][j];
                    auto it = S.upper_bound(ind);
                    R[j] = *it;
                    it--;
                    L[j] = *it;
                }
                for (int j = i; j < Maxm; j += i) if (!B[j].empty())
                    Solve(B[j], B[i]);
            }
            for (int j = 0; j < B[i].size(); j++)
                S.insert(B[i][j]);
            B[i].clear();
        }
        printf("%I64d\n", res);
    }
    return 0;
}