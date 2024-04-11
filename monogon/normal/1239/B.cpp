
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

int n;
string s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> s;
    int cnt = 0;
    int idx = 0, mn = 0;
    rep(i, 0, n) {
        char c = s[i];
        cnt += (c == '(') - (c == ')');
        if(cnt < mn) {
            mn = cnt;
            idx = i + 1;
        }
    }
    if(cnt != 0) {
        cout << "0\n1 1\n";
        return 0;
    }
    rotate(s.begin(), s.begin() + idx, s.end());
    int ans = 0, best = 0;
    int add = 0, x = 0, y = 0, xbest = 0, ybest = 0;
    int cnt2 = 0, prev1 = -1, cnt1 = 0, prev0 = 0;
    rep(i, 0, n) {
        char c = s[i];
        cnt += (c == '(') - (c == ')');
        if(cnt == 2) {
            cnt2++;
        }else if(cnt == 1) {
            cnt1++;
            if(prev1 != -1) {
                if(cnt2 > add) {
                    add = cnt2;
                    x = prev1;
                    y = i;
                }
            }
            prev1 = i + 1;
            cnt2 = 0;
        }else if(cnt == 0) {
            ans++;
            if(cnt1 >= best) {
                best = cnt1;
                xbest = prev0;
                ybest = i;
            }
            cnt1 = 0;
            prev1 = -1;
            cnt2 = 0;
            prev0 = i + 1;
        }
    }
    if(best > ans + add) {
        ans = best; add = 0;
        x = xbest;
        y = ybest;
    }
    x = (x + idx) % n + 1;
    y = (y + idx) % n + 1;
    cout << ans + add << '\n' << x << ' ' << y << '\n';
}