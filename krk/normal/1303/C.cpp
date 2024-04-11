#include <bits/stdc++.h>
using namespace std;

const int Maxl = 26;
const int Maxn = 205;

int T;
char str[Maxn];
int slen;
vector <int> V[Maxl];
bool tk[Maxl];

void Solve()
{
    int cnt = 0, fir = -1;
    for (int i = 0; i < Maxl; i++) {
        sort(V[i].begin(), V[i].end());
        V[i].erase(unique(V[i].begin(), V[i].end()), V[i].end());
        if (V[i].size() >= 3) { printf("NO\n"); return; }
        if (V[i].size() == 1) fir = i;
        if (!V[i].empty()) cnt++;
    }
    vector <int> seq;
    if (cnt > 0) {
        if (fir == -1) { printf("NO\n"); return; }
        fill(tk, tk + Maxl, false);
        while (!tk[fir]) {
            tk[fir] = true; seq.push_back(fir);
            for (int i = 0; i < V[fir].size(); i++) {
                int u = V[fir][i];
                if (!tk[u]) { fir = u; break; }
            }
        }
        if (seq.size() != cnt) { printf("NO\n"); return; }
    }
    for (int i = 0; i < Maxl; i++) if (V[i].empty())
        seq.push_back(i);
    printf("YES\n");
    for (int i = 0; i < seq.size(); i++)
        printf("%c", seq[i] + 'a');
    printf("\n");
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%s", str);
        slen = strlen(str);
        for (int i = 0; i < Maxl; i++)
            V[i].clear();
        for (int i = 0; i + 1 < slen; i++) {
            V[str[i] - 'a'].push_back(str[i + 1] - 'a');
            V[str[i + 1] - 'a'].push_back(str[i] - 'a');
        }
        Solve();
    }
    return 0;
}