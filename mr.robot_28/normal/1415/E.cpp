
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    vector <int> c(n);
    for(int i = 0; i < n; i++)
    {
        cin >> c[i];
    }
    sort(c.begin(), c.end());
    reverse(c.begin(), c.end());
    int sum = 0;
    priority_queue <int> q;
    for(int i = 0; i < k + 1; i++)
    {
        q.push(0);
    }
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        int val = q.top();
        q.pop();
        ans += val;
        val += c[i];
        q.push(val);
    }
    cout << ans;
    return 0;
}