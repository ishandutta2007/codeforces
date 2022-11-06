#include <bits/stdc++.h>
#define pb push_back
#define int long long
#define all(x) (x).begin(), (x).end()
using namespace std;

vector<int> M = {1000000007};
vector<int> P;

mt19937 gen;
int n, q;
string s;
vector<vector<int> > h, p;

int gen_p() {
    int x = gen() % (10000 - 30) + 26;
    if (x % 2 == 0)
        x++;
    return x;
}

int get_hash(int l, int r, int j) {
    int res = h[j][r];
    if (l != 0)
        res -= h[j][l - 1];
    res = (res % M[j] + M[j]) % M[j];
    return res;
}

bool is_eq(int l1, int r1, int l2, int r2) {
    for (int j = 0; j < M.size(); j++)
        if (get_hash(l1, r1, j) * p[j][l2] % M[j] != get_hash(l2, r2, j) * p[j][l1] % M[j]) {
            //cout << j << endl;
            return 0;
        }
    return 1;
}

bool check(int sz) {
    for (int i = 1; i + sz - 1 < n - 1; i++)
        if (is_eq(0, sz - 1, i, i + sz - 1))
            return 1;
    return 0;
}

signed main()
{
    gen.seed(time(0));
    cin >> s;
    n = s.size();
    for (int i = 0; i < M.size(); i++) {
        P.pb({gen_p()});
    }
    h.resize(M.size(), vector<int>(n));
    p.resize(M.size(), vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < p.size(); j++) {
            if (i == 0) {
                h[j][i] = s[i];
                p[j][i] = 1;
            } else {
                p[j][i] = p[j][i - 1] * P[j] % M[j];
                h[j][i] = (h[j][i - 1] + s[i] * p[j][i]) % M[j];
            }
        }
    vector<int> cand;
    for (int sz = 1; sz < n; sz++)
        if (is_eq(0, sz - 1, n - sz, n - 1))
            cand.pb(sz);
    if (cand.size() == 0) {
        cout << "Just a legend";
        return 0;
    }
    int l = 0, r = cand.size();
    while (l < r - 1) {
        int m = (l + r) / 2;
        if (check(cand[m]))
            l = m;
        else
            r = m;
    }
    if (check(cand[l]))
        cout << s.substr(0, cand[l]);
    else
        cout << "Just a legend";
    return 0;
}