#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
             cin.tie(nullptr);                 \
             cout.tie(nullptr)

vector<long long> data;

long long a, b, k, n, m, tmp, ans = 0;


void solve()
{
    cin >> m;
    string a;
    cin >> a;
    for (int i = 0; i < a.size(); ++i)
    {
        if (a[i] == 'U')
        {
            a[i] = 'D';
        }
        else if (a[i] == 'D')
            a[i] = 'U';
    }
    cout << a << endl;
}

int main()
{
    FAST;

    cin >> n;

    while(n--)
        solve();

    return 0;
}