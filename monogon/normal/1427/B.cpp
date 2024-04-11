
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) {
        int n, k;
        string s;
        cin >> n >> k >> s;
        s = "L" + s + "L";
        n += 2;
        char prv = 'L';
        int score = 0;
        vi len;
        int si = 0;
        rep(i, 0, n) {
            if(s[i] == 'W') {
                if(prv == 'W') score += 2;
                else {
                    len.push_back(si);
                    score++;
                }
                si = 0;
            }else if(s[i] == 'L') {
                si++;
            }
            prv = s[i];
        }
        if(sz(len) > 0) {
            len.erase(len.begin());
        }
        sort(all(len));
        int mx = 2 * (n - 2) - 1;
        int idx = 0;
        if(score == 0 && k >= 1) score--;
        while(k--) {
            score += 2;
            if(idx < sz(len)) {
                len[idx]--;
                if(len[idx] == 0) {
                    idx++;
                    score++;
                }
            }
        }
        cout << min(mx, score) << '\n';
    }
}