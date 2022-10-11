#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n, ans = 0, cnt[N];
string s;

bool check(int u)
{
    for (int i = 0; i < u; i++)
    {
        int cur = 0;
        for (int j = i; j < n; j += u)
            cur ^= (s[j] - '0');
        if (cur != 0)
            return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> s;
    for (int i = 0; i < n; i++)
        cnt[__gcd(i, n)]++;
    for (int i = 1; i <= n; i++)
        if (n % i == 0 && check(i))
            ans += cnt[i];
    cout << ans;
}