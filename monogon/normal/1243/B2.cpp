
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int q, n;
string s, t;
int cnt[26];
vector<pair<int, int>> vswap;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> q;
    while(q--) {
        cin >> n >> s >> t;
        fill(cnt, cnt + 26, 0);
        for(char c : s) cnt[c - 'a']++;
        for(char c : t) cnt[c - 'a']++;
        int i;
        for(i = 0; i < 26; i++) {
            if(cnt[i] % 2 == 1) {
                cout << "No" << endl;
                goto endloop;
            }
        }
        cout << "Yes" << endl;
        vswap.clear();
        for(i = 0; i < n; i++) {
            char c = s[i];
            if(t[i] == c) continue;
            for(int j = i + 1; j < n; j++) {
                if(s[j] == c) {
                    swap(s[j], t[i]);
                    vswap.emplace_back(j + 1, i + 1);
                    break;
                }else if(t[j] == c) {
                    swap(s[n - 1], t[j]);
                    swap(s[n - 1], t[i]);
                    vswap.emplace_back(n, j + 1);
                    vswap.emplace_back(n, i + 1);
                    break;
                }
            }
        }
        cout << vswap.size() << endl;
        for(auto &p : vswap) {
            cout << p.first << " " << p.second << endl;
        }
        endloop:;
    }
}