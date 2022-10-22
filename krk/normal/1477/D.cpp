#include <bits/stdc++.h>
using namespace std;

const int Maxn = 500005;

int T;
int n, m;
set <int> neigh[Maxn];
bool rem[Maxn];
int wh[Maxn];
int col;
int A[Maxn], B[Maxn];

void processOne(const vector <int> &seq)
{
    for (int i = 0; i < seq.size(); i++) {
        A[seq[i]] = col - i;
        B[seq[i]] = i == 0? col - int(seq.size()) + 1: col - i + 1;
    }
    col -= int(seq.size());
}

void processTwo(vector <int> seq1, vector <int> seq2)
{
    if (seq1.size() == 1) swap(seq1, seq2);
    if (seq2.size() > 1) {
        processOne(seq1);
        processOne(seq2);
        return;
    }
    for (int i = 0; i < seq1.size(); i++) {
        A[seq1[i]] = col - i;
        B[seq1[i]] = i == 0? col - int(seq1.size()): col - i + 1;
    }
    A[seq2[0]] = col - int(seq1.size());
    B[seq2[0]] = col - int(seq1.size()) + 1;
    col -= (int(seq1.size()) + 1);
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; i++) {
            neigh[i].clear();
            rem[i] = false;
            wh[i] = -1;
        }
        for (int i = 0; i < m; i++) {
            int a, b; scanf("%d %d", &a, &b);
            neigh[a].insert(b);
            neigh[b].insert(a);
        }
        col = n;
        bool flag = true;
        while (flag) {
            flag = false;
            for (int i = 1; i <= n && !flag; i++) if (!rem[i])
                if (neigh[i].size() == col - 1) {
                    A[i] = B[i] = col;
                    col--;
                    for (auto u: neigh[i])
                        neigh[u].erase(i);
                    rem[i] = true;
                    flag = true;
                }
        }
        vector <vector <int> > seq;
        for (int i = 1; i <= n; i++) if (!rem[i] && wh[i] == -1) {
            bool added = false;
            for (int j = 0; j < seq.size() && !added; j++)
                if (neigh[i].find(seq[j][0]) == neigh[i].end()) {
                    wh[i] = j;
                    added = true;
                }
            if (!added)
                for (int j = 1; j <= n; j++) if (!rem[j] && j != i)
                    if (neigh[i].find(j) == neigh[i].end()) {
                        wh[i] = seq.size();
                        seq.push_back({i});
                        wh[j] = seq.size();
                        seq.push_back({j});
                        break;
                    }
        }
        for (int i = 1; i <= n; i++) if (!rem[i])
            if (seq[wh[i]][0] != i)
                seq[wh[i]].push_back(i);
        for (int i = 0; i < seq.size(); i += 2)
            processTwo(seq[i], seq[i + 1]);
        for (int i = 1; i <= n; i++)
            printf("%d%c", A[i], i + 1 <= n? ' ': '\n');
        for (int i = 1; i <= n; i++)
            printf("%d%c", B[i], i + 1 <= n? ' ': '\n');
    }
    return 0;
}