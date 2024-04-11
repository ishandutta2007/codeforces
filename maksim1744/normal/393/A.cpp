#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    string s;
    cin >> s;
    map<char, int> cnt;
    for (char c : s) {
        cnt[c]++;
    }
    cout << min({(cnt['n'] - 1) / 2, cnt['e'] / 3, cnt['i'], cnt['t']}) << '\n';

    return 0;
}