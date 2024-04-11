#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 100111, max_inter = 101, inf = 1000111222;

int dp[max_inter][2][2 * max_n];
vector<pair<int, int> > inter;
vector<int> len;
vector<int> before;

int n, k;
void add() {
    int l = 2 * n, r = 2 * n;
    inter.PB(MP(l, r));
    int cur_before = inter.back().F;
    if (inter.size() > 1) {
        cur_before -= inter[inter.size() - 2].S;
    }
    before.PB(cur_before);
    len.PB(r - l);
}

int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n >> k;
    for (int i = 0; i < k; ++i) {
        int l, r;
        cin >> l >> r;
        inter.PB(MP(l, r));
        int cur_before = inter.back().F;
        if (inter.size() > 1) {
            cur_before -= inter[inter.size() - 2].S;
        }
        before.PB(cur_before);
        len.PB(r - l);
    }
    add();

    for (int i = 0; i <= 2 * n; ++i) {
        dp[0][0][i] = inf;
        dp[0][1][i] = inf;
    }

    for (int i = before[0]; i <= before[0] + len[0]; ++i) {
        dp[0][0][i] = 2;
        dp[0][1][i] = 1;
    }

    dp[0][0][before[0] + len[0]] = 0;


    for (int curi = 1; curi < inter.size(); ++curi) {
        int curb = before[curi];
        int curl = len[curi];

        bool side = 0;
        multiset<int> pr1;
        multiset<int> pr2;
        pr1.insert(inf);
        pr2.insert(inf);

        for (int s0 = 0; s0 <= 2 * n; ++s0) {
            dp[curi][side][s0] = inf;
            if (s0 >= curb + curl) {
                dp[curi][side][s0] = dp[curi - 1][side][s0 - curb - curl];
            }
            //for (int prs0 = max(0, s0 - curl); prs0 <= s0; ++prs0) {
            //    dp[curi][side][s0] = min(dp[curi][side][s0], dp[curi - 1][!side][prs0] + 1);
            //}
            pr1.insert(dp[curi - 1][!side][s0] + 1);
            if (s0 - curl > 0) {
                pr1.erase(pr1.find(dp[curi - 1][!side][s0 - curl - 1] + 1));
            }
            dp[curi][side][s0] = min(dp[curi][side][s0], *pr1.begin());

            //for (int prs0 = max(0, s0 - curb - curl); prs0 <= s0 - curb; ++prs0) {
            //    dp[curi][side][s0] = min(dp[curi][side][s0], dp[curi - 1][side][prs0] + 2);
            //}
            if (s0 - curb >= 0) {
                pr2.insert(dp[curi - 1][side][s0 - curb] + 2);
            }
            if (s0 - curb - curl > 0) {
                pr2.erase(pr2.find(dp[curi - 1][side][s0 - curb - curl - 1] + 2));
            }
            dp[curi][side][s0] = min(dp[curi][side][s0], *pr2.begin());
        }

        pr1.clear();
        pr2.clear();
        pr1.insert(inf);
        pr2.insert(inf);
        side = 1;
        for (int s0 = 0; s0 <= 2 * n; ++s0) {
            dp[curi][side][s0] = dp[curi - 1][side][s0];

            //for (int prs0 = max(0, s0 - curb - curl); prs0 <= s0 - curb; ++prs0) {
            //    dp[curi][side][s0] = min(dp[curi][side][s0], dp[curi - 1][!side][prs0] + 1);
            //}
            if (s0 - curb >= 0) {
                pr1.insert(dp[curi - 1][!side][s0 - curb] + 1);
            }
            if (s0 - curb - curl > 0) {
                pr1.erase(pr1.find(dp[curi - 1][!side][s0 - curb - curl - 1] + 1));
            }
            dp[curi][side][s0] = min(dp[curi][side][s0], *pr1.begin());

            //for (int prs0 = max(0, s0 - curl); prs0 <= s0; ++prs0) {
            //    dp[curi][side][s0] = min(dp[curi][side][s0], dp[curi - 1][side][prs0] + 2);
            //}
            pr2.insert(dp[curi - 1][side][s0] + 2);
            if (s0 - curl > 0) {
                pr2.erase(pr2.find(dp[curi - 1][side][s0 - curl - 1] + 2));
            }
            dp[curi][side][s0] = min(dp[curi][side][s0], *pr2.begin());
        }
    }

    int ans = min(dp[inter.size() - 1][0][n], dp[inter.size() - 1][1][n]);
    if (ans == inf) {
        cout << "Hungry";
        return 0;
    } else {
        cout << "Full\n" << ans;
    }
    return 0;
}