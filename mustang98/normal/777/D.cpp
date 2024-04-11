#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define mp make_pair
#define pb push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 500111;

int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    string s[max_n];
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    int ans = 0;
    for (int i = n - 1; i > 0; --i) {
        bool iscont = false;
        for (int j = 0; j < min(s[i].size(), s[i - 1].size()); ++j) {
            if (s[i - 1][j] > s[i][j]) {
                ans += (s[i-1].size() - j);
                s[i - 1] = s[i - 1].substr(0, j);
                iscont = true;
                break;
            } else if (s[i - 1][j] < s[i][j]) {
                iscont = true;
                break;
            }
        }
        if (iscont) continue;
        if (s[i].size() < s[i - 1].size()) {
            ans += (s[i - 1].size() - s[i].size());
            s[i - 1] = s[i];
        }
    }
    //cout << ans << endl;
    for (int i = 0; i < n; ++i) cout << s[i] << "\n";
    return 0;
}