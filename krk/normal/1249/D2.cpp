#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 200005;

int n, k;
vector <ii> add[Maxn];
set <ii> S;
vector <int> res;

int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        int l, r; scanf("%d %d", &l, &r);
        add[l].push_back(ii(r, i + 1));
    }
    for (int i = 0; i < Maxn; i++) {
        for (int j = 0; j < add[i].size(); j++)
            S.insert(add[i][j]);
        while (!S.empty() && S.begin()->first < i)
            S.erase(S.begin());
        while (S.size() > k) {
            auto it = S.end(); it--;
            res.push_back(it->second);
            S.erase(it);
        }
    }
    printf("%d\n", int(res.size()));
    for (int i = 0; i < res.size(); i++)
        printf("%d%c", res[i], i + 1 < res.size()? ' ': '\n');
    return 0;
}