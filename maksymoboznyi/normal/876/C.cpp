#include <bits/stdc++.h>
#define int long long
#define small -2000000000000000000
#define big 2000000000000000000
#define pb push_back
using namespace std;

int sum(int x)
{
    int ans = 0;
    while (x > 0)
    {
        ans += x%10;
        x /= 10;
    }
    return ans;
}
int n;
vector<int> ans;
signed main()
{
    cin >> n;
    for (int s = 0; s < 91; s++)
    {
        int x = n - s;
        if (sum(x) == s)
            ans.pb(x);
    }
    if (ans.size() == 0)
        cout << 0;
    else
    {
        sort(ans.begin(), ans.end());
        cout << ans.size() <<endl;
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << ' ';
    }
    return 0;
}