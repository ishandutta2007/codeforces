#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1005;

int T;
int n, k;
int cnt[Maxn], a[Maxn][Maxn];
int res[Maxn];
int cur[Maxn];
int mx;

int Ask()
{
    vector <int> seq;
    for (int i = 1; i <= n; i++)
        if (!cur[i]) seq.push_back(i);
    if (seq.empty()) return 0;
    printf("? %d", int(seq.size()));
    for (int i = 0; i < seq.size(); i++)
        printf(" %d", seq[i]);
    printf("\n"); fflush(stdout);
    int res; scanf("%d", &res);
    return res;
}

void fillZer(const vector <int> &V)
{
    for (int i = 0; i < V.size(); i++)
        res[V[i]] = mx;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &k);
        vector <int> seq;
        for (int i = 0; i < k; i++) {
            scanf("%d", &cnt[i]);
            for (int j = 0; j < cnt[i]; j++)
                scanf("%d", &a[i][j]);
            seq.push_back(i);
        }
        fill(cur + 1, cur + n + 1, 0);
        mx = Ask();
        while (!seq.empty()) {
            fill(cur + 1, cur + n + 1, 0);
            vector <int> h[2];
            for (int i = 0; i < seq.size(); i++) {
                int ind = seq[i];
                if (i % 2 == 0)
                    for (int j = 0; j < cnt[ind]; j++)
                        cur[a[ind][j]]++;
                h[i % 2].push_back(ind);
            }
            int st = Ask();
            if (st == mx) { fillZer(h[0]); seq = h[1]; }
            else {
                fillZer(h[1]);
                if (seq.size() == h[0].size()) {
                    res[seq[0]] = st;
                    break;
                } else seq = h[0];
            }
        }
        printf("!");
        for (int i = 0; i < k; i++)
            printf(" %d", res[i]);
        printf("\n"); fflush(stdout);
        string dum; cin >> dum;
    }
    return 0;
}