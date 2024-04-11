#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 100005;

int n, m;
vector <int> R[Maxn], C[Maxn];
ll res;

void Add(vector <int> &V)
{
    if (V.empty()) return;
    sort(V.begin(), V.end());
    for (int i = 0; i + 1 < V.size(); i++)
        res += ll(V[i + 1] - V[i]) * (i + 1) * (int(V.size()) - i - 1);
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            int x; scanf("%d", &x);
            R[x].push_back(i);
            C[x].push_back(j);
        }
    for (int i = 0; i < Maxn; i++) {
        Add(R[i]);
        Add(C[i]);
    }
    cout << res << endl;
    return 0;
}