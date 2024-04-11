
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;

int t, n;
string s;
int cnt[3];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> s;
        n = s.length();
        fill(cnt, cnt + 3, 0);
        int j = 0;
        int ans = INT_MAX;
        rep(i, 0, n) {
            while(j < n && (cnt[0] == 0 || cnt[1] == 0 || cnt[2] == 0)) {
                cnt[s[j] - '1']++;
                j++;
            }
            if(cnt[0] > 0 && cnt[1] > 0 && cnt[2] > 0) {
                ans = min(ans, j - i);
            }
            cnt[s[i] - '1']--;
        }
        cout << (ans == INT_MAX ? 0 : ans) << '\n';
    }
}