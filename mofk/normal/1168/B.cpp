#include <bits/stdc++.h>

using namespace std;

string s;
int n;
int f[300005];
vector <int> p[2];

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> s;
    n = s.size();
    for (int i = 0; i <= n; ++i) f[i] = n;
    for (int i = 0; i < n; ++i) {
        int x = s[i] - '0';
        for (int j = (int)p[x].size() - 1; j >= 0; --j) {
            int k = p[x][j];
            if (i + i - k < n && s[i+i-k] - '0' == x) {
                f[k] = min(f[k], i + i - k);
                break;
            }
        }
        p[x].push_back(i);
    }
    long long ans = 0;
    for (int i = n - 1; i >= 0; --i) f[i] = min(f[i], f[i+1]);
    for (int i = 0; i < n; ++i) ans += n - f[i];
    cout << ans << endl;
    return 0;
}