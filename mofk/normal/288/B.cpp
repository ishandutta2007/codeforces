#include <bits/stdc++.h>
#define ff(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fb(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define pb push_back

typedef long long ll;
using namespace std;
typedef vector <int> vi;

const int mod = 1000000007;
int N, K;

int main(void) {
    cin >> N >> K;
    int ans = 1;
    ff(i, 1, K - 1) ans = 1ll * ans * K % mod;
    ff(i, 1, N - K) ans = 1ll * ans * (N - K) % mod;
    cout << ans << endl;
    return 0;
}