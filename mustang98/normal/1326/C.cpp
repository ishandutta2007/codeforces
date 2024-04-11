#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 200111, inf = 1000111222;
const ll mod = 998244353;

int m[max_n];
int pos[max_n];

int main()
{
    //freopen("input.txt", "r", stdin);
    int n, k;
    cin >> n >> k;
    vector<int> p;
    for (int i = 0; i < n; ++i) {
        scanf("%d", m + i);
        --m[i];
        pos[m[i]] = i;
    }
    ll sum = 0;
    for (int i = 0; i < k; ++i) {
        int cur = n - i - 1;
        sum += (cur + 1);;
        p.push_back(pos[cur]);
    }
    sort(p.begin(), p.end());
    ll ans = 1;
    for (int i = 0; i + 1 < p.size(); ++i) {
        ans = ans * (p[i + 1] - p[i]);
        ans %= mod;
    }
    cout << sum << ' ' << ans << endl;

    return 0;
}