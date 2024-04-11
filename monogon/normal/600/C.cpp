
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int n;
string s;
int cnt[26];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> s;
    n = s.length();
    for(char c : s) cnt[c - 'a']++;
    // minimum number of changes = # odd characters if n even, or #odd - 1 if n odd
    // only change one character from each odd group
    // pair the larger half with the smaller half
    set<char> se;
    for(int i = 25; i >= 0; i--) {
        if(cnt[i] % 2) se.insert(i);
    }
    int k = se.size();
    int i = 0;
    for(int x : se) {
        if(i < k / 2) cnt[x]++;
        else if(i >= (k + 1) / 2) cnt[x]--;
        i++;
    }
    string mid = "", ans = "";
    for(int i = 0; i < 26; i++) {
        if(cnt[i] % 2) {
            mid += (i + 'a');
            cnt[i]--;
        }
        for(int j = 0; j < cnt[i]; j += 2) {
            ans += (i + 'a');
        }
    }
    string ans2(ans.begin(), ans.end());
    reverse(ans2.begin(), ans2.end());
    cout << ans << mid << ans2 << '\n';
}