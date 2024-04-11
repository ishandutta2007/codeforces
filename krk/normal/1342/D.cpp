#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int n, k;
int cnt[Maxn];
int c[Maxn];
int prv[Maxn];
vector <int> add[Maxn];
vector <vector <int> > res;
vector <int> seq;

int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        int m; scanf("%d", &m);
        cnt[m]++;
    }
    for (int i = 1; i <= k; i++) {
        scanf("%d", &c[i]);
        if (c[i] != c[i - 1]) prv[i] = i - 1;
        else prv[i] = prv[i - 1];
    }
    for (int i = k; i >= 1; i--) {
        for (int j = 0; j < add[i].size(); j++)
            seq.push_back(add[i][j]);
        while (cnt[i] > 0)
            if (seq.empty()) { seq.push_back(res.size()); res.push_back(vector<int>()); }
            else {
                int ind = seq.back();
                res[ind].push_back(i); cnt[i]--;
                if (res[ind].size() >= c[i]) {
                    add[prv[i]].push_back(ind);
                    seq.pop_back();
                }
            }
    }
    printf("%d\n", int(res.size()));
    for (int i = 0; i < res.size(); i++) {
        printf("%d", int(res[i].size()));
        for (int j = 0; j < res[i].size(); j++)
            printf(" %d", res[i][j]);
        printf("\n");
    }
    return 0;
}