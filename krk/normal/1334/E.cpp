#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <ll, int> lli;

const int mod = 998244353;
const int Maxm = 1005;

int C[Maxm][Maxm];
ll n;
vector <lli> seq, cur;
map <ll, vector <lli> > M;

void Gen(int lvl, ll num)
{
    if (lvl >= seq.size()) M.insert(make_pair(num, cur));
    else {
        Gen(lvl + 1, num);
        cur.push_back(lli(seq[lvl].first, 0));
        for (cur.back().second = 1; cur.back().second <= seq[lvl].second; cur.back().second++) {
            num *= seq[lvl].first;
            Gen(lvl + 1, num);
        }
        cur.pop_back();
    }
}

int Solve(const vector <int> &V)
{
    int sum = 0;
    for (int i = 0; i < V.size(); i++)
        sum += V[i];
    int res = 1;
    for (int i = 0; i < V.size(); i++) {
        res = ll(res) * C[sum][V[i]] % mod;
        sum -= V[i];
    }
    return res;
}

int main()
{
    for (int i = 1; i < Maxm; i++) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; j++)
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
    }
    scanf("%I64d", &n);
    for (ll i = 2; i * i <= n; i++) if (n % i == 0) {
        int cnt = 0;
        while (n % i == 0) {
            n /= i;
            cnt++;
        }
        seq.push_back(lli(i, cnt));
    }
    if (n > 1) seq.push_back(lli(n, 1));
    Gen(0, 1);
    int q; scanf("%d", &q);
    while (q--) {
        ll lef, rig; scanf("%I64d %I64d", &lef, &rig);
        vector <int> L, R;
        auto A = M[lef], B = M[rig];
        int i = 0, j = 0;
        while (i < A.size() || j < B.size())
            if (i < A.size() && (j >= B.size() || A[i].first < B[j].first)) {
                L.push_back(A[i].second);
                i++;
            } else if (j < B.size() && (i >= A.size() || B[j].first < A[i].first)) {
                R.push_back(B[j].second);
                j++;
            } else if (A[i].second > B[j].second) {
                L.push_back(A[i].second - B[j].second);
                i++;
                j++;
            } else if (A[i].second < B[j].second) {
                R.push_back(B[j].second - A[i].second);
                i++;
                j++;
            } else {
                i++;
                j++;
            }
        int res = ll(Solve(L)) * Solve(R) % mod;
        printf("%d\n", res);
    }
    return 0;
}