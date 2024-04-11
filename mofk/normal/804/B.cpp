#include <bits/stdc++.h>
#define ff(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fb(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define pb push_back

typedef long long ll;
using namespace std;
typedef vector <int> vi;

const int mod = 1000000007;
string s;
int g[1000006];

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> s;
    int N = s.size();
    ff(i, 1, N) g[i] = (g[i-1] + g[i-1] + 1) % mod;
    int ans = 0;
    int cnt = 0;
    ff(i, 0, s.size() - 1) {
        if (s[i] == 'a') ++cnt;
        else ans = (ans + g[cnt]) % mod;
    }
    cout << ans << endl;
    return 0;
}