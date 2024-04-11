#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 100005;
const int Maxd = 10;

struct pos {
    int vals[Maxd];
    pos() {
        fill(vals, vals + Maxd, 0);
    }
};

int n, q;
char str[Maxn];
int pref[Maxn][Maxd];
int seq[Maxn], slen;
pos BIT[Maxn];
int ql[Maxn], qr[Maxn];
vector <int> bylef[Maxn], byrig[Maxn];
set <ii> S;
pos res[Maxn];
vector <ii> st;

void Add(int ind, const pos &p)
{
    for (int i = ind; i > 0; i -= i & -i)
        for (int j = 0; j < Maxd; j++)
            BIT[i].vals[j] += p.vals[j];
}

pos Get(int ind)
{
    pos p;
    for (int i = ind; i < Maxn; i += i & -i)
        for (int j = 0; j < Maxd; j++)
            p.vals[j] += BIT[i].vals[j];
    return p;
}

void Compute(pos &res, int lef, int rig, bool back)
{
    for (int j = 0; j < Maxd; j++)
        res.vals[j] += pref[rig][j] - pref[lef - 1][j];
    if (back) {
        int ind = lower_bound(seq, seq + slen, lef) - seq;
        if (ind < slen && seq[ind] <= rig) rig = seq[ind] - 1;
        for (int j = 0; j + 1 < Maxd; j++)
            res.vals[j] += pref[rig][j + 1] - pref[lef - 1][j + 1];
    }
    pos add = Get(lef);
    for (int j = 0; j < Maxd; j++)
        res.vals[j] += add.vals[j];
}

bool Fall(const ii &lef, const ii &rig)
{
    int mx = Maxd - 1;
    while (mx >= 0 && pref[rig.first - 1][mx] - pref[lef.second][mx] == 0)
        mx--;
    pos p;
    for (int i = 0; i <= mx; i++) {
        int num = pref[rig.first - 1][i] - pref[lef.second][i];
        if (num == 0) continue;
        for (int j = 0; j < i; j++)
            p.vals[j] += num;
    }
    Add(lef.first, p);
    return mx % 2 == 0;
}

void clearSet(int lef, int rig)
{
    auto it = S.end();
    while (it != S.begin()) {
        it--;
        if (it->first <= lef) break;
        int ind = it->second;
        Compute(res[ind], ql[ind], min(qr[ind], rig), true);
        S.erase(it++);
    }
}

int main()
{
    scanf("%d %d", &n, &q);
    scanf("%s", str + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < Maxd; j++)
            pref[i][j] = pref[i - 1][j];
        if (str[i] == '<' || str[i] == '>') seq[slen++] = i;
        else pref[i][str[i] - '0']++;
    }
    for (int i = 0; i < q; i++) {
        scanf("%d %d", &ql[i], &qr[i]);
        bylef[ql[i]].push_back(i);
        byrig[qr[i]].push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < bylef[i].size(); j++) {
            int ind = bylef[i][j];
            S.insert(make_pair(ql[ind], ind));
        }
        if (str[i] == '>')
            st.push_back(ii(i, i));
        else if (str[i] == '<') {
            ii cur = ii(i, i);
            while (!st.empty()) {
                clearSet(st.back().first, i);
                if (Fall(st.back(), cur)) {
                    st.back().second = i;
                    break;
                }
                cur.first = st.back().first;
                st.pop_back();
            }
            if (st.empty())
                clearSet(0, i);
        }
        for (int j = 0; j < byrig[i].size(); j++) {
            int ind = byrig[i][j];
            if (S.find(ii(ql[ind], ind)) != S.end()) {
                Compute(res[ind], ql[ind], qr[ind], false);
                S.erase(ii(ql[ind], ind));
            }
        }
    }
    for (int i = 0; i < q; i++)
        for (int j = 0; j < Maxd; j++)
            printf("%d%c", res[i].vals[j], j + 1 < Maxd? ' ': '\n');
    return 0;
}