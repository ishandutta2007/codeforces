#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const int N = 1e3 + 5;
ll n, s[N], d[N];

int main()
{
    ios_base::sync_with_stdio();
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> s[i] >> d[i];
    ll now = 1;
    for (int i = 1; i <= n; i++)
    {
        now = max(now, s[i]);
        ll q = now-s[i];
        q = q % d[i];
        now++;
        if (q == 0)
            continue;
        else
            now += d[i] - q;
    }
    cout << now-1;
    return 0;
}