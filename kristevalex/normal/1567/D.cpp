#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
             cin.tie(nullptr);                 \
             cout.tie(nullptr)

vector<long long> data;

long long a, b, k, n, m, tmp, ans = 0;



long long get_val(long long x)
{
    long long cur = 0;
    for (int i = 0; i < 11; ++i)
    {
        if (x >= ::data[i] - 1)
        {
            cur = ::data[i] - 1;
        }
        else
        {
            break;
        }
    }

    return cur;
}

void solve()
{
    cin >> a >> b;

    if (b == 1)
    {
        cout << a << endl;
        return;
    }

    ans = a - b;



    for (int i = 0; i < b; ++i)
    {
        if (i == b - 1)
        {
            cout << ans + 1 << endl;
            break;
        }
        int as = get_val(ans);
        ans -= as;
        cout << as + 1 << " ";
    }
}

int main()
{
    FAST;


    cin >> n;

    ::data.resize(13);
    ::data[0] = 1;
    for (int i = 1; i < 13; ++i)
    {
        ::data[i] = ::data[i-1]*10;
    }



    while(n--)
        solve();

    return 0;
}