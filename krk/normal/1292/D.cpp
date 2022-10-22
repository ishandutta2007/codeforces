#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 5001;
const int Maxm = 700;
const ll Inf = 9000000000000000000ll;

struct lin {
    int lef, rig;
    ll val;
};

int mx[Maxn];
vector <int> pr;
int m;
int cnt[Maxn];
ll has[Maxn][Maxm];
ll tot[Maxn][Maxm];
ll res = Inf;

int main()
{
    for (int i = 2; i < Maxn; i++) if (mx[i] == 0) {
        pr.push_back(i);
        for (int j = i; j < Maxn; j += i)
            mx[j] = pr.size();
    }
    for (int i = 2; i < Maxn; i++) {
        for (int j = 0; j < pr.size(); j++)
            has[i][j] = has[i - 1][j];
        int num = i;
        while (num > 1) {
            int cur = mx[num] - 1;
            has[i][cur]++;
            num /= pr[cur];
        }
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        int num; scanf("%d", &num);
        cnt[num]++;
    }
    for (int i = 1; i < Maxn; i++) {
        ll cur = 0;
        for (int j = 0; j < pr.size(); j++) {
            tot[i][j] = cur;
            cur += ll(cnt[i]) * has[i][j];
        }
        tot[i][pr.size()] = cur;
    }
    vector <lin> seq;
    seq.push_back(lin{1, Maxn - 1, 0ll});
    for (int z = int(pr.size()) - 1; z >= 0; z--) {
        vector <lin> nxt;
        for (int c = 0; c < seq.size(); c++) {
            int lef = seq[c].lef, rig = seq[c].rig;
            vector <lin> tmp;
            ll cand = seq[c].val;
            int totcnt = 0;
            for (int i = lef; i <= rig; i++) {
                totcnt += cnt[i];
                cand += tot[i][z + 1];
            }
            res = min(res, cand);
            for (int i = lef, j; i <= rig; i = j) {
                j = i;
                while (j <= rig && has[i][z] == has[j][z]) j++;
                tmp.push_back(lin{i, j - 1, seq[c].val});
            }
            for (int i = 0; i < tmp.size(); i++) {
                cand = tmp[i].val + ll(m - totcnt) * has[tmp[i].lef][z];
                for (int j = lef; j <= rig; j++) if (j < tmp[i].lef || j > tmp[i].rig)
                    cand += ll(cnt[j]) * abs(has[j][z] - has[tmp[i].lef][z]) + tot[j][z];
                tmp[i].val = cand;
            }
            for (int i = 0; i < tmp.size(); i++)
                nxt.push_back(tmp[i]);
        }
        seq = nxt;
    }
    for (int i = 0; i < seq.size(); i++)
        res = min(res, seq[i].val);
    printf("%I64d\n", res);
    return 0;
}