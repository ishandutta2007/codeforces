#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+5;

int n;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    if (n == 1)
        cout << "2\n" << 1 << ' ' << 1;
    if (n == 2)
        cout << "3\n2 1 2";
    else {
        vector<int> ans;
        for (int i = 2; i <= n; i+=2)
            ans.push_back(i);

        for (int i = 1; i <= n; i+=2)
            ans.push_back(i);

        for (int i = 2; i <= n; i+=2)
            ans.push_back(i);
        cout << ans.size()<<endl;

        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << ' ';
    }
    return 0;
}