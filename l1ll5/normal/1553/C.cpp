#include<bits/stdc++.h>
using namespace std;
const int N = 100000 + 5;
using LL = long long;

string s;
int ans;
int p[N];
int tun[N];
void dfs(int x) {
    if (x == 10) {
        int A = 0, B = 0;
        for (int i = 0; i < 10; i += 1) {
            if (s[i] == '1') {
                if (i & 1) B++;
                else A++;
            }
            if ((9 - i) / 2 + A < B) {
                ans = min(ans, i + 1);
                break;
            }
            if ((10 - i) / 2 + B < A) {
                ans = min(ans, i + 1);
                break;
            }
        }
        return;
    }
    if (s[x] == '?') {
        s[x] = '0';
        dfs(x + 1);
        s[x] = '1';
        dfs(x + 1);
        s[x] = '?';
        return;
    }
    dfs(x + 1);
}
int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        cin >> s;
        ans = 10;
        dfs(0);
        cout << ans << '\n';
    }
}
/*
ABABABABAB
4433221100
544
*/