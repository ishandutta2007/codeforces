#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int n = s.length();
    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            for (int k = j + 1; k < n; k++)
                if (s[i] == 'Q' && s[j] == 'A' && s[k] == 'Q')
                    ans++;
    cout << ans << endl;
}