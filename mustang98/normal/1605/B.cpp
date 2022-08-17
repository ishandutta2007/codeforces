#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 1, inf = 1000111222;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int T;
    cin >> T;
    while (T--) {
            int n;
    cin >> n;
        string s;
        cin >> s;
        if (is_sorted(s.begin(), s.end())) {
            puts("0");
            continue;
        }
        vector<int> v[2];
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '0') v[0].PB(i);
            else v[1].PB(i);
        }
        reverse(v[1].begin(), v[1].end());
        vector<int> ans;
        while(!v[0].empty() && !v[1].empty() && v[1].back() < v[0].back()) {
            ans.PB(v[1].back());
            ans.PB(v[0].back());
            v[1].pop_back();
            v[0].pop_back();
        }
        sort(ans.begin(), ans.end());
        cout << 1 << "\n";
        cout << ans.size() << ' ';
        for (int x : ans) {
            cout << x + 1 << ' ';
        }
        cout << "\n";
    }

    return 0;
}