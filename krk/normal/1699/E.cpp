#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxm = 5000005;

int T;
int n, m;
int mn, mx;
bool has[Maxm];
int val[Maxm];
vector <int> my[Maxm];

bool Eliminate(int ind)
{
    while (!my[ind].empty()) {
        int v = my[ind].back();
        if (val[v] != ind) my[ind].pop_back();
        else return false;
    }
    return true;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        mn = m; mx = m;
        for (int i = 1; i <= m; i++) {
            has[i] = false;
            val[i] = i;
            my[i].clear();
        }
        for (int i = 1; i <= n; i++) {
            int a; scanf("%d", &a);
            if (has[a]) continue;
            has[a] = true;
            my[a].push_back(a);
            mn = min(mn, a);
        }
        int res = Maxm;
        for (int i = m; i > 0; i--) {
            if (ll(i) * i <= m)
                for (int j = i * i; j <= m; j += i) {
                    int cand = val[j / i];
                    if (cand < val[j]) {
                        val[j] = cand;
                        if (has[j]) my[val[j]].push_back(j);
                    }
                }
            if (i <= mn) {
                while (Eliminate(mx)) mx--;
                res = min(res, mx - i);
            }
        }
        printf("%d\n", res);
    }
    return 0;
}