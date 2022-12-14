#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
             cin.tie(nullptr);                 \
             cout.tie(nullptr)

vector<long long> data;

long long a, b, k, n, m, tmp, ans = 0;



int solve()
{
    cin >> n >> a;

    ::data.resize(n);

    for (int i = 0; i < n; ++i)
        cin >> ::data[i];

    sort(::data.begin(), ::data.end());

    long long val = ::data[n-1] + ::data[n-2];

    ans = a / val;
    a -= ans*val;
    ans *= 2;

    if (a > 0)
    {
        ans++;
        a-= ::data[n-1];
    }

if (a > 0)
    {
        ans++;
        a-= ::data[n-2];
    }




    cout << ans << endl;

    return 0;
}


int main()
{
    FAST;


    int t;
    cin >> t;
    while(t--)
        solve();




    return 0;
}