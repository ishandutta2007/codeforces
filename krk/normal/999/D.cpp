#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;

int n, m;
int a[Maxn];
vector <int> V[Maxn];
set <int> S;
ll res;

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        V[a[i] % m].push_back(i);
    }
    int st = 0;
    while (st < m && V[st].size() <= n / m) st++;
    if (st < m) {
        for (int i = 0; i < m; i++) if (V[i].size() < n / m)
            S.insert(i);
        for (int i = st; i < m; i++)
            while (V[i].size() > n / m) {
                auto it = S.lower_bound(i);
                if (it == S.end()) it = S.begin();
                int ind = V[i].back(); V[i].pop_back();
                int tk = (*it - i + m) % m;
                a[ind] += tk; V[*it].push_back(ind);
                res += tk;
                if (V[*it].size() >= n / m) S.erase(it);
            }
    }
    cout << res << endl;
    for (int i = 0; i < n; i++)
        printf("%d%c", a[i], i + 1 < n? ' ': '\n');
    return 0;
}