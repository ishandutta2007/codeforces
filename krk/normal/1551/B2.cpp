#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int T;
int n, k;
vector <int> seq[Maxn];
int res[Maxn];

void Empty(vector <int> &V)
{
    for (int i = 0; i < V.size(); i++)
        res[V[i]] = i + 1;
    V.clear();
}

int main()
{
    cin >> T;
    while (T--) {
        scanf("%d %d", &n, &k);
        for (int i = 1; i <= n; i++)
            seq[i].clear();
        for (int i = 0; i < n; i++) {
            res[i] = 0;
            int a; scanf("%d", &a);
            seq[a].push_back(i);
        }
        vector <int> cur;
        for (int i = 1; i <= n; i++) {
            int add = min(int(seq[i].size()), k);
            for (int j = 0; j < add; j++) {
                cur.push_back(seq[i][j]);
                if (cur.size() == k) Empty(cur);
            }
        }
        for (int i = 0; i < n; i++)
            printf("%d%c", res[i], i + 1 < n? ' ': '\n');
    }
    return 0;
}