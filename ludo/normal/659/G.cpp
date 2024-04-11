#include <algorithm>
#include <iostream>

using namespace std;

typedef long long ll;

const ll mod = 1e9 + 7;

#define MAXN 1000000
int N, h[MAXN + 1];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    ll sum = 0;
    for (int i = N; i > 0; i--) {
        cin >> h[i];
        sum += --h[i];
    }
    sum %= mod;

    int r = 2;
    ll sr = min(h[r - 1], h[r]);
    while (r <= N) {
        sum = (sum + min(h[r - 1], h[r]) * sr) % mod;
        if (r + 1 <= N) {
            sr = (sr * min(min(h[r - 1], h[r]), h[r + 1]) + min(h[r], h[r + 1])) % mod;
        }
        r++;
    }
    cout << sum << endl;
    return 0;
}