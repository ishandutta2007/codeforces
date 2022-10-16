#include <bits/stdc++.h>
#define ff(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fb(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define pb push_back

typedef long long ll;
using namespace std;
typedef vector <int> vi;

int N;
int ans[1000005];

void solve(int n) {
    if (n <= 0) return;
    if (n == 1) { ans[0] = 1; ans[1] = 0; return; }
    int k = 1; while (k <= n) k *= 2; k /= 2;
    ff(i, k, n) { ans[i] = 2 * k - i - 1; ans[2*k-i-1] = i; }
    solve(2 * k - n - 2);
}

int main(void) {
    cin >> N;
    solve(N);
    ll res = 0;
    ff(i, 0, N) res += (ans[i] ^ i);
    cout << res << "\n";
    ff(i, 0, N) cout << ans[i] << " "; cout << endl;
    return 0;
}