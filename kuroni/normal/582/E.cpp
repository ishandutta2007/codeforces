#include <bits/stdc++.h>
using namespace std;

const int N = 16, MOD = 1E9 + 7;

int n, u, cur = 0, msk = 0, pos[4], neg[4];
string s;

vector<int> fast_subset_transform(vector<int> a, bool inv, int typ) {
    vector<int> ans = a;
    for (int n = ans.size(), step = 1; step < n; step *= 2) {
        for (int i = 0; i < n; i += 2 * step) {
            for (int j = i; j < i + step; j++) {
                int &u = ans[j], &v = ans[j + step];
                if (typ == 0) {
                    tie(u, v) = inv ? pair(v, (u - v) % MOD) : pair((u + v) % MOD, u); // OR
                } else {
                    tie(u, v) = inv ? pair((v - u) % MOD, u) : pair(v, (u + v) % MOD); // AND
                }
            }
        }
    }
    return ans;
}

vector<int> parse() {
    // variable
    if (s[cur] != '(') {
        vector<int> ret(1 << n, 0);
        switch (s[cur]) {
            case 'A':
                ret[pos[0]]++; break;
            case 'B':
                ret[pos[1]]++; break;
            case 'C':
                ret[pos[2]]++; break;
            case 'D':
                ret[pos[3]]++; break;
            case 'a':
                ret[neg[0]]++; break;
            case 'b':
                ret[neg[1]]++; break;
            case 'c':
                ret[neg[2]]++; break;
            case 'd':
                ret[neg[3]]++; break;
            default:
                for (int i = 0; i < 4; i++) {
                    ret[pos[i]]++;
                    ret[neg[i]]++;
                }
                break;
        }
        ++cur;
        return ret;
    }

    // expression
    vector<int> ans(1 << n, 0);
    int msk = 0;
    ++cur; vector<int> le = parse(); ++cur;
    switch (s[cur++]) {
        case '|':
            msk = 1; break;
        case '&':
            msk = 2; break;
        case '?':
            msk = 3; break;
    }
    ++cur; vector<int> ri = parse(); cur++;
    for (int op = 0; op < 2; op++) {
        if (msk >> op & 1) {
            vector<int> cle = fast_subset_transform(le, false, op);
            vector<int> cri = fast_subset_transform(ri, false, op);
            vector<int> ret(1 << n);
            for (int i = 0; i < (1 << n); i++) {
                ret[i] = 1LL * cle[i] * cri[i] % MOD;
            }
            ret = fast_subset_transform(ret, true, op);
            for (int i = 0; i < (1 << n); i++) {
                (ans[i] += ret[i]) %= MOD;
            }
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> s >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> u;
            pos[j] |= (u << i);
            neg[j] |= ((u ^ 1) << i);
        }
        cin >> u; msk |= (u << i);
    }
    vector<int> tot = parse();
    cout << (tot[msk] + MOD) % MOD;
}