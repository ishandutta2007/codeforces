#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;

struct pos {
    int x;
    int delt;
    pos() {}
    pos(int x, int delt): x(x), delt(delt) {}
    bool operator<(const pos &oth) const {
        if (x != oth.x) return x < oth.x;
        return delt < oth.delt;
    }
};

int n, h, m, k;
int cur;
int val[Maxn];
vector <pos> seq;
int res, wth;

int main()
{
    scanf("%d %d %d %d", &n, &h, &m, &k);
    int mod = m / 2;
    for (int i = 0; i < n; i++) {
        int h, m; scanf("%d %d", &h, &m);
        m %= mod; val[i] = m;
        if (m + k < mod) {
            seq.push_back(pos(m, 1));
            seq.push_back(pos(m + k, -1));
        } else {
            cur++;
            seq.push_back(pos(m, 1));
            seq.push_back(pos((m + k) % mod, -1));
        }
    }
    sort(seq.begin(), seq.end());
    res = cur; wth = 0;
    for (int i = 0; i < seq.size(); i++) {
        if (seq[i].delt == 1) {
            if (cur < res) { res = cur; wth = seq[i].x; }
            cur++;
        } else {
            cur--;
            if (cur < res) { res = cur; wth = seq[i].x; }
        }
    }
    printf("%d %d\n", res, wth);
    vector <int> seq;
    for (int i = 0; i < n; i++)
        if (val[i] + k < mod) {
            if (val[i] < wth && wth < val[i] + k)
                seq.push_back(i);
        } else if (val[i] < wth || wth < (val[i] + k) % mod)
            seq.push_back(i);
    for (int i = 0; i < seq.size(); i++)
        printf("%d%c", seq[i] + 1, i + 1 < seq.size()? ' ': '\n');
    return 0;
}