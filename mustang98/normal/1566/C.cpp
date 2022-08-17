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

int calc(string s) {
    int ans = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '0') {
            ++ans;
        }
    }
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '1') {
            if (i - 1 >= 0 && s[i - 1] == '0') {
                s[i - 1] = '#';
                ++ans;
                continue;
            }
            if (i + 1 < s.size() && s[i + 1] == '0') {
                s[i + 1] = '#';
                ++ans;
                continue;
            }
        }
    }
    return ans;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string a, b;
        cin >> a;
        cin >> b;
        int ans = 0;
        string s;
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] != b[i]) {
                ans += calc(s);
                s.clear();
                ans += 2;
            } else {
                s += a[i];
            }
        }
        ans += calc(s);
        cout << ans << "\n";
    }

    return 0;
}