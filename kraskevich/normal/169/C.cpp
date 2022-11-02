#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <cmath>
using namespace std;

typedef long long ll;
#define F first
#define S second
#define pb push_back

const ll mod = 1000 * 1000 * 1000 + 7;
ll f[5000][5000];

int main() {
    ios_base::sync_with_stdio(0);
    string s, t;
    cin >> s >> t;
    int n = s.length(), m = t.length();
    for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j) {
                    f[i][j] = (j ? f[i][j - 1] : 0);
                    if(s[i] == t[j]) f[i][j] += (i && j ? f[i - 1][j - 1] : 0) + 1;
                    f[i][j] %= mod;
            }
    ll ans = 0;
    for(int i = 0; i < n; ++i) 
            ans += f[i][m - 1];
    cout << ans % mod;
    cin >> n;
    return 0;
}