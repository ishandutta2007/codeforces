#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

struct triple {
    int a, b, c;
    triple(int a = 0, int b = 0, int c = 0): a(a), b(b), c(c) {}
};

int T;
int n, m;
vector <int> neigh[Maxn];
vector <triple> seq;
set <int> R;

bool Less(const triple &a, const triple &b)
{
    return a.c < b.c;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; i++)
            neigh[i].clear();
        for (int i = 0; i < m; i++) {
            int a, b; scanf("%d %d", &a, &b);
            neigh[a].push_back(b);
        }
        seq.clear();
        for (int i = 1; i <= n; i++)
            for (int j = 0; j < neigh[i].size(); j++) {
                int u = neigh[i][j];
                for (int k = 0; k < neigh[u].size(); k++) {
                    int z = neigh[u][k];
                    seq.push_back(triple(i, u, z));
                }
            }
        sort(seq.begin(), seq.end(), Less);
        R.clear();
        for (int i = 0; i < seq.size(); i++)
            if (!R.count(seq[i].a) && !R.count(seq[i].b))
                R.insert(seq[i].c);
        printf("%d\n", int(R.size()));
        bool pr = false;
        for (set <int>::iterator it = R.begin(); it != R.end(); it++) {
            if (pr) printf(" ");
            else pr = true;
            printf("%d", *it);
        }
        printf("\n");
    }
    return 0;
}