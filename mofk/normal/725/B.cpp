#include <bits/stdc++.h>
#define ff(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fb(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define pb push_back

typedef long long ll;
using namespace std;
typedef vector <int> vi;

const int v[] = {3,4,5,2,1,0};
string s;
ll N, M;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> s;
    ff(i, 0, (int)s.size() - 2) N = N * 10 + (s[i] - '0');
    M = v[s[s.size()-1] - 'a'];
    ll ns = (N - 1) / 4;
    ll ans = ns * 16 + M + 1;
    if (N % 2 == 0) ans += 7;
    cout << ans << endl;
    return 0;
}