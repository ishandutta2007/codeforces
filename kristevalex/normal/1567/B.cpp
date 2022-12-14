#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
             cin.tie(nullptr);                 \
             cout.tie(nullptr)

vector<long long> data;

long long a, b, k, n, m, tmp, ans = 0;


void solve()
{
    cin >> a >> b;
    if (::data[a - 1] == b)
        cout << a << endl;
    else
        {
            k = ::data[a - 1] ^ b;
            if (k == a)
                cout << a + 2 << endl;
            else
                cout << a + 1 << endl;
        }
}

int main()
{
    FAST;

    cin >> n;

    ::data.resize(300007);
    ::data[0] = 0;
    for (int i = 1; i < 300007; ++i)
    {
        ::data[i] = ::data[i-1] ^ i;
        /*if (i < 10)
            cout << ::data[i] << endl;*/
    }

    while(n--)
        solve();

    return 0;
}