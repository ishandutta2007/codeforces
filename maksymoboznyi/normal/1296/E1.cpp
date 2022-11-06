#include <bits/stdc++.h>
#define pb push_back
#define ll long long

using namespace std;

const int N = 2e5 + 5;

vector<int> pos[200];
int ans[N], used[N], lst[N];
int cur = 0;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    string s;
    cin >> n >> s;
    for (int i = 0; i < s.size(); i++) {
        for (int j = 1; j <= 100; j++)
            if (lst[j] <= s[i]) {
                ans[i] = j;
                lst[j] = max(lst[j], int(s[i]));
                break;
            }
    }
    for (int i = 0; i < s.size(); i++)
        cur = max(cur, ans[i]);
    if (cur > 2) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    for (int i = 0; i < s.size(); i++)
        cout << ans[i]-1;
    return 0;
}