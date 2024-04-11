#include <bits/stdc++.h>    
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

const ll MOD = 1000 * 1000 * 1000 + 7;
const int N = 1000 * 1000;

ll p2[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    p2[0] = 1;
    for (int i = 1; i < N; i++)
        p2[i] = p2[i - 1] * 2 % MOD;
    int n;
    cin >> n;
    vector<ll> x(n);
    for (int i = 0; i < n; i++)
        cin >> x[i];
    ll res = 0;
    sort(x.begin(), x.end());
    for (int i = 0; i < n; i++) {
         ll low = p2[i];
         ll high = p2[n - i - 1];
         res -= high * x[i];
         res += low * x[i];
         res = (res % MOD + MOD) % MOD;
    }
    cout << res << endl;
}