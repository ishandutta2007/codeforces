#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100010;
const int64 mod = 10007;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

#ifdef MARX
    freopen("data.in", "r", stdin);
#endif

    int n; cin >> n;

    vector<int64> v(n);

    for (int i = 0; i < n; ++i){
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    int64 ans = 0;

    for (int i = 0; i < n; ++i){
        ans = (ans + v[i] * v[n - i - 1] % mod) % mod;
    }

    cout << ans << endl;

    return 0;
}