#include <bits/stdc++.h>
using namespace std;

const int Maxn = 300600;
const int Maxl = 26;
const int Maxd = 550;

struct pos {
    int nxt[Maxl];
    multiset <int> S;
    int best;
    pos() {
        fill(nxt, nxt + Maxl, 0);
        best = -1;
    }
};

char tmp[Maxn];
int n, m;
string nam[Maxn];
int val[Maxn];
pos seq[Maxn];
int slen;
vector <int> big;
int intree[Maxn];
char str[Maxn];
int stlen;
int Z[Maxn];

void Read(string &s)
{
    scanf("%s", tmp);
    s = tmp;
}

bool Solve(const string &a, const string &b)
{
    if (b.length() < a.length()) return false;
    stlen = 0;
    for (int i = 0; i < a.length(); i++)
        str[stlen++] = a[i];
    for (int i = 0; i < b.length(); i++)
        str[stlen++] = b[i];
    int L = -1, R = -1;
    for (int i = 1; i < stlen; i++) {
        if (i <= R) Z[i] = min(Z[i - L], R - i);
        else Z[i] = 0;
        while (i + Z[i] < stlen && str[Z[i]] == str[i + Z[i]])
            Z[i]++;
        if (i >= a.length() && Z[i] >= a.length())
            return true;
        if (i + Z[i] - 1 > R) {
            R = i + Z[i] - 1;
            L = i;
        }
    }
    return false;
}

int main()
{
    scanf("%d %d", &n, &m);
    slen++;
    for (int i = 0; i < n; i++) {
        Read(nam[i]);
        if (nam[i].length() >= Maxd) big.push_back(i);
        else {
            int cur = 1;
            for (int j = 0; j < nam[i].length(); j++) {
                int let = nam[i][j] - 'a';
                if (!seq[cur].nxt[let]) seq[cur].nxt[let] = ++slen;
                cur = seq[cur].nxt[let];
            }
            intree[i] = cur;
            seq[cur].S.insert(val[i]);
            seq[cur].best = val[i];
        }
    }
    while (m--) {
        int typ; scanf("%d", &typ);
        if (typ == 1) {
            int ind, x; scanf("%d %d", &ind, &x); ind--;
            if (intree[ind]) {
                int me = intree[ind];
                seq[me].S.erase(seq[me].S.find(val[ind]));
                seq[me].S.insert(x);
                seq[me].best = *seq[me].S.rbegin();
            }
            val[ind] = x;
        } else {
            string Q; Read(Q);
            int res = -1;
            for (int i = 0; i < Q.length(); i++) {
                int cur = 1;
                for (int j = i; j < Q.length() && cur; j++) {
                    int let = Q[j] - 'a';
                    cur = seq[cur].nxt[let];
                    res = max(res, seq[cur].best);
                }
            }
            for (int i = 0; i < big.size(); i++) {
                int ind = big[i];
                if (val[ind] <= res) continue;
                if (Solve(nam[ind], Q)) res = val[ind];
            }
            printf("%d\n", res);
        }
    }
    return 0;
}