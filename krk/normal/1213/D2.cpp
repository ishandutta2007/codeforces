#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int n, k;
vector <int> tims[Maxn];
int res = 1000000000;

int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        int a; scanf("%d", &a);
        tims[a].push_back(0);
        int cnt = 0;
        while (a) {
            a /= 2;
            cnt++;
            tims[a].push_back(cnt);
        }
    }
    for (int i = 0; i < Maxn; i++) if (tims[i].size() >= k) {
        sort(tims[i].begin(), tims[i].end());
        int cand = 0;
        for (int j = 0; j < k; j++)
            cand += tims[i][j];
        res = min(res, cand);
    }
    printf("%d\n", res);
    return 0;
}