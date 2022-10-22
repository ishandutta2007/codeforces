#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef pair <int, ii> iii;
typedef long long ll;

const int Maxn = 100005;
const int Maxm = 2;

int n;
ii B[Maxn][Maxm];
priority_queue <iii> Q;
ll res;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < Maxm; j++)
            scanf("%d %d", &B[i][j].first, &B[i][j].second);
        int g1 = B[i][0].first - B[i][1].second;
        int g2 = B[i][0].second - B[i][1].first;
        if (g1 + g2 >= 0) {
            res += g1;
            Q.push(iii(B[i][0].first + B[i][0].second, ii(i, 0)));
        } else if (g1 >= 0) res += g1;
        else if (g2 >= 0) res -= g2;
    }
    int cur = 0;
    while (!Q.empty()) {
        int g = Q.top().first;
        ii v = Q.top().second; Q.pop();
        res += g * (v.second - cur);
        if (v.second == 0)
            Q.push(iii(B[v.first][1].first + B[v.first][1].second, ii(v.first, 1)));
        cur = 1 - cur;
    }
    cout << res << endl;
    return 0;
}