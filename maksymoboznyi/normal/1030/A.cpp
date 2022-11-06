#include <bits/stdc++.h>
#define pb push_back
#define int long long

using namespace std;

const int N = 1e5 + 5;
const long long inf = 2e18;


signed main()
{
    ios_base::sync_with_stdio();
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int s = 0;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        s += x;
    }
    if (s == 0)
        cout << "EASY";
    else
        cout << "HARD";
    return 0;
}