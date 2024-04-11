
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int n, k;
string s;
int c[26];
char ch;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k >> s;
    for(int i = 0; i < k; i++) {
        cin >> ch;
        c[ch - 'a'] = true;
    }
    ll cnt = 0;
    ll ans = 0;
    for(int i = 0; i <= n; i++) {
        if(i == n || !c[s[i] - 'a']) {
            ans += cnt * (cnt + 1) / 2;
            cnt = 0;
        }else cnt++;
    }
    cout << ans << endl;
}