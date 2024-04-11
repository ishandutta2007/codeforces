#include <bits/stdc++.h>
using namespace std;

const int Maxn = 3005;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int n;
vector <int> seq;
int res[Maxn][Maxn];
set <int> inds;
int nils = 0;
int ans[Maxn];

int getRes(int a, int b)
{
    if (a > b) swap(a, b);
    if (res[a][b]) return res[a][b];
    printf("? %d %d\n", a, b); fflush(stdout);
    scanf("%d", &res[a][b]);
    return res[a][b];
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        seq.push_back(i);
    shuffle(seq.begin(), seq.end(), rng);
    int all = (1 << 20) - 1;
    inds.insert(0);
    for (int i = 1; i < seq.size(); i++) {
        int got = getRes(seq[i], seq[*inds.begin()]);
        if ((got & nils) == 0) {
            for (auto it: inds) {
                got = getRes(seq[i], seq[it]);
                nils |= (got ^ all);
            }
            for (auto it = inds.begin(); it != inds.end(); )
                if ((getRes(seq[i], seq[*it]) ^ all) != nils)
                    inds.erase(it++);
                else it++;
            inds.insert(i);
        }
    }
    int a = *inds.begin(), b = *inds.rbegin();
    vector <int> seq2;
    for (int i = 0; i < n; i++) if (i != a && i != b)
        seq2.push_back(i);
    shuffle(seq2.begin(), seq2.end(), rng);
    for (int i = 0; i < seq2.size(); i++) {
        int ind = seq2[i];
        int g1 = getRes(seq[a], seq[ind]);
        int g2 = getRes(seq[b], seq[ind]);
        if (g1 != g2) {
            if (g1 > g2) swap(a, b);
            break;
        }
    }
    for (int i = 1; i <= n; i++)
        if (seq[a] == i) ans[i] = 0;
        else ans[i] = getRes(seq[a], i);
    printf("!");
    for (int i = 1; i <= n; i++)
        printf(" %d", ans[i]);
    printf("\n"); fflush(stdout);
    return 0;
}