#include <bits/stdc++.h>

using namespace std;

int n;
string s;
int cnt[500];

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> s;
    if (n == 1) return cout << "Yes" << endl, 0;
    for (int i = 0; i < n; ++i) ++cnt[s[i]];
    for (int i = 'a'; i <= 'z'; ++i) if (cnt[i] > 1) return cout << "Yes" << endl, 0;
    cout << "No" << endl;
    return 0;
}