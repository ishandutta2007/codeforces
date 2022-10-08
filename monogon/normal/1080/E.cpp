
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
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

const int N = 255;
int n, m, cnt[N][26];
string s[N];
bool palin[N];

bool check(int i, int j) {
    if(!palin[i] || !palin[j]) return false;
    rep(c, 0, 26) {
        if(cnt[i][c] != cnt[j][c]) return false;
    }
    return true;
}

ll ans = 0;

void manacher() {
    vi d1(n), d2(n);
    for(int i = 0, l = 0, r = -1; i < n; i++) {
        if(!palin[i]) {
            l = i + 1;
            r = i;
            continue;
        }
        int k = (i > r ? 1 : min(r - i + 1, d1[l + r - i]));
        while(0 <= i - k && i + k < n && check(i - k, i + k)) {
            k++;
        }
        ans += k;
        d1[i] = k--;
        if(i + k > r) {
            r = i + k;
            l = i - k;
        }
    }
    for(int i = 0, l = 0, r = -1; i < n; i++) {
        if(!palin[i]) {
            l = i + 1;
            r = i;
            continue;
        }
        int k = (i > r ? 0 : min(r - i + 1, d2[l + r - i + 1]));
        while(0 <= i - k - 1 && i + k < n && check(i - k - 1, i + k)) {
            k++;
        }
        ans += k;
        d2[i] = k--;
        if(i + k > r) {
            r = i + k;
            l = i - k - 1;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    rep(i, 0, n) {
        cin >> s[i];
    }
    rep(i, 0, m) {
        rep(k, 0, n) fill(cnt[k], cnt[k] + 26, 0);
        rep(j, i, m) {
            rep(k, 0, n) {
                cnt[k][s[k][j] - 'a']++;
                int num = 0;
                rep(c, 0, 26) {
                    num += (cnt[k][c] & 1);
                }
                palin[k] = (num <= 1);
            }
            manacher();
        }
    }
    cout << ans << '\n';
}