#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;

int n;
int P[Maxn];
int in[Maxn];
vector <int> seq[Maxn];
int par[Maxn];
ll res;

void unionSet(int a, int b, int wh)
{
    a = par[a], b = par[b];
    if (a == b) return;
    if (seq[a].size() < seq[b].size()) swap(a, b);
    for (int i = 0; i < seq[b].size(); i++) {
        int my = P[seq[b][i]];
        res += my < wh && par[in[wh - my]] == a;
        seq[a].push_back(seq[b][i]);
    }
    for (int i = 0; i < seq[b].size(); i++)
        par[seq[b][i]] = a;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &P[i]);
        in[P[i]] = i;
        seq[i].push_back(i);
        par[i] = i;
    }
    for (int i = 1; i <= n; i++) {
        if (in[i] > 1 && P[in[i] - 1] < i) {
            seq[par[in[i] - 1]].push_back(in[i]);
            par[in[i]] = par[in[i] - 1];
        }
        if (in[i] < n && P[in[i] + 1] < i)
            unionSet(in[i], in[i] + 1, i);
    }
    cout << res << endl;
    return 0;
}