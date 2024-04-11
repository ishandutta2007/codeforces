#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int n;
int cnt[26];
string s;
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    cin >> s;
    if (n == 1) {
        cout << "Yes";
        return 0;
    }
    for (int i = 0; i < s.size(); i++) {
        cnt[s[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
        if (cnt[i] >= 2) {
            cout << "Yes";
            return 0;
        }
    }
    cout << "No";
    return 0;
}