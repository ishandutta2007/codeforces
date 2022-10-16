#include <bits/stdc++.h>
#define ff(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fb(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define pb push_back

typedef long long ll;
using namespace std;
typedef vector <int> vi;

int N;
vi a;
int cnt[5005];
int s[5005];

int main(void) {
    cin >> N; a.assign(N, 0);
    ff(i, 0, N - 1) cin >> a[i];
    sort(a.begin(), a.end());
    ff(i, 1, N - 1) ff(j, 0, i - 1) ++cnt[a[i]-a[j]];
    ff(i, 1, 5000) s[i] = s[i-1] + cnt[i];
    ll res = 0;
    ff(i, 3, 5000) ff(j, 1, i - 2) res += 1ll * cnt[i] * cnt[j] * s[i-j-1];
    double d = res / double(N * (N - 1) / 2);
    ff(i, 1, 2) d /= N * (N - 1) / 2;
    cout << setprecision(10) << fixed << d << endl;
    return 0;
}