#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 600006;

int n;
int A[Maxn], B[Maxn];
vector <int> byA[Maxn];
vector <int> res1, res2;

vector <int> Solve()
{
    for (int i = 0; i < Maxn; i++)
        byA[i].clear();
    set <ii> S;
    for (int i = 0; i < n; i++) if (A[i] < B[i]) {
        byA[A[i]].push_back(i);
        S.insert(ii(B[i], i));
    }
    vector <int> res;
    int pnt = Maxn - 1;
    while (!S.empty()) {
        set <ii>::iterator it = S.end(); it--;
        int b = it->first, ind = it->second; S.erase(it);
        res.push_back(ind);
        while (pnt >= b) {
            for (int i = 0; i < byA[pnt].size(); i++) {
                int ind2 = byA[pnt][i];
                S.erase(ii(B[ind2], ind2));
            }
            pnt--;
        }
    }
    return res;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d %d", &A[i], &B[i]);
    res1 = Solve();
    for (int i = 0; i < n; i++) {
        A[i] = 2 * n + 1 - A[i];
        B[i] = 2 * n + 1 - B[i];
    }
    res2 = Solve();
    if (res1.size() < res2.size()) res1 = res2;
    printf("%d\n", int(res1.size()));
    for (int i = 0; i < res1.size(); i++)
        printf("%d%c", res1[i] + 1, i + 1 < res1.size()? ' ': '\n');
    return 0;
}