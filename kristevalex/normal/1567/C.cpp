#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
             cin.tie(nullptr);                 \
             cout.tie(nullptr)

vector<long long> data;

long long a, b, k, n, m, tmp, ans = 0;

long long div_ (long long x, int pw)
{
    //cout << "div x: " << x << ", pw: " << pw << " " << ::data[pw] << endl;

    if (x < ::data[pw])
        return -10;

        //cout << "div  " << (x / ::data[pw]) % 10 << endl;

    if ((x / ::data[pw]) % 10 > 0)
        return x - ::data[pw];
    else
        return div_(x + 9 * ::data[pw], pw + 2);
}

long long get_value(long long x)
{
    if (x < 0) return 0;
    if (x < 10) return x + 1;

    long long wout = get_value(x / 10);
    //cout << "value of " << x/10 << ": " << wout << endl;
    long long with = get_value(div_(x / 10, 1));
    //cout << "value of " << div_(x / 10, 1) << ": " << with << endl;

    long long as = 0;

    for (int i = 0; i < 10; ++i)
    {
        int j = x%10 - i;
        if (j >= 0)
            as += wout;
    }

    for (int i = 0; i < 10; ++i)
    {
        int j = 10 + x%10 - i;
        if (j < 10)
            as += with;
    }

    return as;
}


void solve()
{
    cin >> m;
    cout << get_value(m) - 2 << endl;
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


    //cout << div_(10, 1) << endl;

    while(n--)
        solve();

    return 0;
}