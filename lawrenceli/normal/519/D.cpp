#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 100100;

int n, x[30];
map<ll, int> num[30];
char s[MAXN];

int main() {
    for (int i=0; i<26; i++) cin >> x[i];
    cin >> s; n = strlen(s);
    ll p = 0, ans = 0;
    for (int i=0; i<n; i++) {
        int a = s[i]-'a';
        ans += num[a][p];
        p += x[a], num[a][p]++;
    }
    cout << ans;
}