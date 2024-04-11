#include <bits/stdc++.h>
#define pii pair<int, string>
#define par pair<pii, int>
#define x first
#define y second
#define eb emplace_back
#define sz(a) int((a).size())
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const int N = 1e5 + 10;
int t, n;
char s[N];
void solve() {
    cin >> n >> (s + 1);
    if(n == 1) {
        cout << s[1] << s[1] << endl;
        return;
    }
    if(s[1] <= s[2]) {
        cout << s[1] << s[1] << endl;
        return;
    }
    int k = n;
    for(int i = 3; i <= n; i++) {
        if(s[i - 1] < s[i]) {
            k = i - 1;
            break;
        }
    }
    for(int i = 1; i <= k; i++) cout << s[i];
    for(int i = k; i >= 1; i--) cout << s[i];
    cout << endl;
    return;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    for(cin >> t; t--; solve());
    return 0;
}