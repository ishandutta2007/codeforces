#include <bits/stdc++.h>
#define ff(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fb(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define pb push_back

typedef long long ll;
using namespace std;
typedef vector <int> vi;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int N, K; cin >> N >> K;
    int ans = 0;
    ff(i, 1, N) if (K + 5 * i <= 240) K += 5 * i, ++ans; else break;
    cout << ans << endl;
    return 0;
}