#include <bits/stdc++.h>
#define ff(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fb(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define pb push_back

typedef long long ll;
using namespace std;
typedef vector <int> vi;

int N, M, cntN, cntM;

int solve(int n, int m) {
    set <int> s;
    ff(i, 1, cntN) { s.insert(n % 7); n /= 7; }
    ff(i, 1, cntM) { s.insert(m % 7); m /= 7; }
    return s.size() == cntN + cntM;
}

int main(void) {
    cin >> N >> M; --N; --M;
    int tmp = N;
    while (tmp) { tmp /= 7; ++cntN; }
    if (!cntN) ++cntN;
    tmp = M;
    while (tmp) { tmp /= 7; ++cntM; }
    if (!cntM) ++cntM;
    if (cntN + cntM > 7) return cout << 0 << endl, 0;
    ll ans = 0;
    ff(i, 0, N) ff(j, 0, M) ans += solve(i, j);
    cout << ans << endl;
    return 0;
}