#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;

const int Maxn = 200005;
const ll Inf = 9000000000000000000;

int n;
map <int, vector <ii> > M;
vector <vector <ii> > seq;
ll dp[Maxn][2];

bool Less(const ii &a, const ii &b)
{
    if (a.first != b.first) return a.first < b.first;
    return a.second > b.second;
}

ll getDist(const ii &a, const ii &b) { return abs(a.first - b.first) + abs(a.second - b.second); }

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x, y; scanf("%d %d", &x, &y);
        M[max(x, y)].push_back(ii(x, y));
    }
    for (map <int, vector <ii> >::iterator it = M.begin(); it != M.end(); it++) {
        seq.push_back(it->second);
        sort(seq.back().begin(), seq.back().end(), Less);
    }
    fill((ll*)dp, (ll*)dp + Maxn * 2, Inf);
    dp[0][0] = getDist(ii(0, 0), seq[0][0]);
    dp[0][1] = getDist(ii(0, 0), seq[0].back());
    for (int i = 0; i + 1 < seq.size(); i++)
        for (int j = 0; j < 2; j++) {
            dp[i][j] += getDist(seq[i][0], seq[i].back());
            for (int k = 0; k < 2; k++) {
                ii a = j == 1? seq[i][0]: seq[i].back();
                ii b = k == 0? seq[i + 1][0]: seq[i + 1].back();
                dp[i + 1][k] = min(dp[i + 1][k], dp[i][j] + getDist(a, b));
            }
        }
    ll best = min(dp[int(seq.size()) - 1][0], dp[int(seq.size()) - 1][1]) +
              getDist(seq.back()[0], seq.back().back());
    cout << best << endl;
    return 0;
}