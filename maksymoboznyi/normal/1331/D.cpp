#include <bits/stdc++.h>
#define pb push_back
#define int long long
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    if ((s.back() - '0') % 2 == 0)
        cout << 0;
    else
        cout << 1;
    return 0;
}