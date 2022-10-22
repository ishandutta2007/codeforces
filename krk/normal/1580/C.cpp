#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef pair <int, ii> iii;

const int Maxn = 200005;
const int Maxm = 450;

int n, m;
int X[Maxn], Y[Maxn];
vector <int> my[Maxn];
int delt[Maxn];
int res[Maxn];
vector <iii> seq[Maxm];

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d %d", &X[i], &Y[i]);
    for (int i = 1; i <= m; i++) {
        int a, b; scanf("%d %d", &a, &b);
        my[b].push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        if (my[i].size() % 2) my[i].push_back(m + 1);
        for (int j = 0; j + 1 < my[i].size(); j += 2) {
            int a = my[i][j], b = my[i][j + 1];
            a += X[i];
            if (a >= b) continue;
            if (X[i] + Y[i] >= Maxm) 
                while (a < b) {
                    delt[a]++;
                    int to = min(b, a + Y[i]);
                    delt[to]--;
                    a += X[i] + Y[i];
                }
            else seq[X[i] + Y[i]].push_back(iii(Y[i], ii(a, b)));
        }
    }
    for (int i = 1; i <= m; i++) {
        res[i] = res[i - 1] + delt[i];
        delt[i] = 0;
    }
    for (int i = 1; i < Maxm; i++) {
        for (int j = 0; j < seq[i].size(); j++) {
            iii p = seq[i][j];
            int a = p.second.first, b = p.second.second;
            for (int el = 0; el < p.first && a + el < b; el++) {
                delt[a + el]++;
                int dif = (b - 1 - a - el) / i;
                int nxt = a + el + dif * i + i;
                if (nxt <= m) delt[nxt]--;
            }
        }
        for (int s = 1; s <= m; s++) {
            if (s >= i) delt[s] += delt[s - i];
            res[s] += delt[s];
        }
        fill(delt + 1, delt + m + 1, 0);
    }
    for (int i = 1; i <= m; i++)
        printf("%d\n", res[i]);
    return 0;
}