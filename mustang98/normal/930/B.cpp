#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 5011, max_l = 26, inf = 1000111222;

vector<int> pos[max_l];
string s;

int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> s;
    for (int i = 0; i < s.size(); ++i) {
        pos[s[i] - 'a'].PB(i);
    }
    int cnt_good = 0;
    for (int let = 0; let < 26; ++let) {
        if (pos[let].size() < 2) {
            cnt_good += pos[let].size();
            continue;
        }

        vector<int>& p = pos[let];

        int max1 = 0;
        for (int i = 0; i < s.size(); ++i) {
            int cnt[26] = {0};
            for (int j = 0; j < p.size(); ++j) {
                int shift = p[j];
                cnt[s[(shift + i) % s.size()] - 'a']++;
            }
            int cur1 = 0;
            for (int j = 0; j < 26; ++j) {
                if (cnt[j] == 1) {
                    cur1++;
                }
            }
            if (cur1 > max1) {
                max1 = cur1;
            }
        }
        cnt_good += max1;
    }

    ld ans = 1.0 * cnt_good / s.size();
    cout << fixed << setprecision(10) << ans;

    return 0;
}