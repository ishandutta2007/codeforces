#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

const int MAXN = 100100;

int n, ar[MAXN];
vector<int> nums[2];

int main() {
    ios_base::sync_with_stdio(0);
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> ar[i];
        ar[i]--;
        nums[ar[i]].push_back(i);
    }

    vector<pii> ans;
    for (int t=1; t<=n; t++) {
        int cur = 0;
        vector<int> win;
        while (cur < n) {
            int nxt = 1e9, winner = -1;
            for (int i=0; i<2; i++) {
                int ind = lower_bound(nums[i].begin(), nums[i].end(), cur)-nums[i].begin();
                if (ind+t-1 < nums[i].size())
                    if (nums[i][ind+t-1] < nxt)
                        nxt = nums[i][ind+t-1], winner = i;
            }
            if (nxt == 1e9) {
                win.clear(); break;
            } else {
                win.push_back(winner);
                cur = nxt+1;
            }
        }

        if (!win.empty()) {
            int cnt[2] = {0, 0};
            for (int i=0; i+1<win.size(); i++)
                cnt[win[i]]++;
            if (cnt[win.back()] >= cnt[!win.back()])
                ans.push_back(pii(cnt[win.back()]+1, t));
        }
    }

    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for (int i=0; i<ans.size(); i++)
        cout << ans[i].first << ' ' << ans[i].second << '\n';
    return 0;
}