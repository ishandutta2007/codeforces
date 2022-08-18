#include <bits/stdc++.h>

using namespace std;

int main()
{
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    string a, b;
    int ans = 0;
    map<string, int> cnt;
    while(n--)
    {
        cin >> a >> b >> b;
        for(auto &c: a)
            c = tolower(c);
        for(auto &c: b)
            c = tolower(c);
        cnt[a] = cnt[b] + 1;
        ans = max(ans, cnt[a]);
    }
    cout << ans + 1 << "\n";
}