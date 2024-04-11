#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int N = 2e5 + 5;

int n, k;
string s;
int kol[N][27];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        cin >> s;
        for (int i = 0; i < k; i++)
            for (int c = 0; c < 26; c++)
                kol[i][c] = 0;
        for (int i = 0; i < n; i++)
            kol[i % k][s[i] - 'a']++;
        for (int i = 0; i < k / 2; i++)
            for (int c = 0; c < 26; c++)
                kol[i][c] += kol[k - i - 1][c];
        int ans = 0;
        for (int i = 0; i < (k + 1) / 2; i++) {
            int sum = 0, mx = 0;
            for (int c = 0; c < 26; c++)
                sum += kol[i][c], mx = max(mx, kol[i][c]);
            ans += sum - mx;
        }
        cout << ans << "\n";
    }
    return 0;
}