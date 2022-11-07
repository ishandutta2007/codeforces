#include <bits/stdc++.h>
#define pb push_back
#define ll long long
using namespace std;

ll s1, s2, a, b, n;
vector<char> ans;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a >> b;
        if (s1+a - s2 > 500)
        {
            ans.pb('G');
            s2 += b;
        }else
        {
            ans.pb('A');
            s1 += a;
        }
    }
    if (abs(s1 - s2) <= 500)
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i];
    else
        cout << -1;
    return 0;
}