#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;
const int Maxd = 3;

int n, m;
char str[Maxn];
int my[Maxn][Maxd];

int main()
{
    scanf("%d %d", &n, &m);
    scanf("%s", str + 1);
    for (int i = 1; i <= n; i++) {
        if (i >= Maxd)
            for (int j = 0; j < Maxd; j++)
                my[i][j] = my[i - Maxd][j];
        my[i][str[i] - 'a']++;
    }
    for (int i = 1; i <= m; i++) {
        int l, r; scanf("%d %d", &l, &r);
        int mx = 0;
        vector <int> seq = {0, 1, 2};
        do {
            int cand = 0;
            for (int j = 0; j < Maxd; j++) {
                int lef = l, rig = r;
                while (lef % Maxd != j) lef++;
                if (lef > rig) continue;
                while (rig % Maxd != j) rig--;
                cand += my[rig][seq[j]];
                if (lef >= Maxd) cand -= my[lef - Maxd][seq[j]];
            }
            mx = max(mx, cand);
        } while (next_permutation(seq.begin(), seq.end()));
        printf("%d\n", r - l + 1 - mx);
    }
    return 0;
}