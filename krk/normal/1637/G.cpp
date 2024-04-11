#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = (1 << 20) + 5;

bool good[Maxn];
int T;
int n;
vector <int> seq;
vector <int> res;
vector <ii> ans;

void Solve(vector <int> &V)
{
    if (V.size() <= 1) {
        for (int i = 0; i < V.size(); i++)
            res.push_back(V[i]);
        return;
    }
    int pnt = int(V.size()) - 1;
    while (!good[V[pnt]]) pnt--;
    int tims = int(V.size()) - 1 - pnt;
    int l = pnt - 1, r = pnt + 1;
    vector <int> nxt;
    res.push_back(V[pnt]);
    for (int i = 0; i < tims; i++) {
        ans.push_back(ii(V[l], V[r]));
        res.push_back(V[l] + V[r]);
        nxt.push_back(V[r] - V[l]);
        l--; r++;
    }
    for (int i = 0; i < 2 * tims + 1; i++)
        V.pop_back();
    Solve(V);
    Solve(nxt);
}

int main()
{
    for (int i = 0; i < 20; i++)
        good[1 << i] = true;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        if (n == 2) { printf("-1\n"); continue; }
        seq.clear(); res.clear();
        ans.clear();
        for (int i = 1; i <= n; i++)
            seq.push_back(i);
        Solve(seq);
        sort(res.begin(), res.end());
        if (res[0] != res.back()) {
            int i = 0;
            while (i + 1 < res.size() && res[i] != res[i + 1]) i++;
            assert(i + 1 < res.size());
            assert(res[i] != res.back());
            ans.push_back(ii(res[i], res[i]));
            res[i] *= 2; res[i + 1] = 0;
            for (int j = 0; j < res.size(); j++) if (res[j])
                while (res[j] < res.back()) {
                    ans.push_back(ii(res[j], 0));
                    ans.push_back(ii(res[j], res[j]));
                    res[j] *= 2;
                }
            ans.push_back(ii(res.back(), 0));
        }
        printf("%d\n", int(ans.size()));
        for (int i = 0; i < ans.size(); i++)
            printf("%d %d\n", ans[i].first, ans[i].second);
    }
    return 0;
}