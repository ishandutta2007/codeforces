#include <bits/stdc++.h>

#define F first
#define S second
#define MP make_pair
#define PB push_back

using namespace std;

typedef long long ll;
typedef long double ld;

const int max_n = -1, inf = 1000111222;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        string s1 = s;
        sort(s1.begin(), s1.end());
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] != s1[i]) ++ans;
        }
        cout << ans << "\n";
    }


    return 0;
}