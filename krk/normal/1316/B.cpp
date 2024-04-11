#include <bits/stdc++.h>
using namespace std;

int T;
int n;
string s;

int main()
{
    cin >> T;
    while (T--) {
        cin >> n;
        cin >> s;
        string res = s;
        int best = 1;
        for (int i = 2; i <= n; i++) {
            string cur = s.substr(i - 1);
            string lft = s.substr(0, i - 1);
            if ((n - i + 1) % 2) reverse(lft.begin(), lft.end());
            cur += lft;
            if (cur < res) {
                res = cur;
                best = i;
            }
        }
        cout << res << "\n";
        cout << best << "\n";
    }
    return 0;
}