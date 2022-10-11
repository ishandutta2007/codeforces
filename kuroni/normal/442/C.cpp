#include <bits/stdc++.h>
using namespace std;
 
int n, u;
long long ans = 0;
vector<int> ve;
 
int main()
{
    cin >> n;
    while (n--)
    {
        cin >> u;
        while (ve.size() >= 2 && ve.back() <= min(ve[ve.size() - 2], u))
        {
            ans += min(ve[ve.size() - 2], u);
            ve.pop_back();
        }
        ve.push_back(u);
    }
    for (int i = 1; i < ve.size() - 1; i++)
        ans += min(ve[i - 1], ve[i + 1]);
    cout << ans;
}