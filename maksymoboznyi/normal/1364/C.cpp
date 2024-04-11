#include <bits/stdc++.h>
#define pb push_back
#define vi vector<int>
#define all(x) (x).begin(), (x).end()
#define pi pair<int, int>
#define int long long
using namespace std;

const int N = 3e5 + 5;

int n, a[N];

signed main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    set<int> q1, q2;
    for (int i = 0; i < a[n]; i++)
        q1.insert(i);
    for (int i = a[n] + 1; i <= n + 1; i++)
        q2.insert(i);
    vector<int> ans;
    for (int i = n - 1; i > 0; i--)
        if (a[i] == a[i + 1]) {
            ans.pb(*q2.begin()), q2.erase(q2.begin());
        }
        else {
            ans.pb(a[i]);
            while (*q1.rbegin() != a[i]) {
                auto it = q1.end();
                it--;
                q2.insert(*it);
                q1.erase(it);
            }
            auto it = q1.end();
            it--;
            q1.erase(it);
        }
    if (q1.size() != 0)
        ans.pb(*q1.begin());
    else
        ans.pb(*q2.begin());
    reverse(all(ans));
    for (auto x: ans)
        cout << x << ' ';
    return 0;
}