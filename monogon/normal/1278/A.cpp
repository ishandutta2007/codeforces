
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int t;
string p, h;
int cnt[26];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> p >> h;
        if(h.length() < p.length()) {
            cout << "NO" << endl;
            continue;
        }
        fill(cnt, cnt + 26, 0);
        for(int i = 0; i < p.length(); i++) {
            cnt[h[i] - 'a']++;
            cnt[p[i] - 'a']--;
        }
        for(int i = p.length(); i <= h.length(); i++) {
            int j = 0;
            for(; j < 26; j++) {
                if(cnt[j] != 0) break;
            }
            if(j == 26) {
                cout << "YES" << endl;
                goto endloop;
            }
            if(i < h.length()) {
                cnt[h[i] - 'a']++;
                cnt[h[i - p.length()] - 'a']--;
            }
        }
        cout << "NO" << endl;
        endloop:;
    }
}