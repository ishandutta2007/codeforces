#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    int64 a = 1, b = 1;
    int64 mod = 1000000007;
    for (int i = 0; i < n; ++i)
        a = a * 27 % mod, b = b * 7 % mod;
    int64 ans = (a - b + mod) % mod;
    cout << ans << endl;

    return 0;
}