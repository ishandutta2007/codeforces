
#include <bits/stdc++.h>

#define ll long long
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int) (x).size())
#define pii pair<int, int>
#define vi vector<int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)

using namespace std;

const int N = 2e3 + 5;
int n, k;
string s[N];
int maxA[N][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    rep(i, 0, n) {
        cin >> s[i];
    }
    rep(i, 0, n) rep(j, 0, n) {
        int opt1 = (i > 0 ? (s[i - 1][j] == 'a' ? 1 : 0) + maxA[i - 1][j] : 0);
        int opt2 = (j > 0 ? (s[i][j - 1] == 'a' ? 1 : 0) + maxA[i][j - 1] : 0);
        maxA[i][j] = max(opt1, opt2);
    }
    if(2 * n - 2 - maxA[n - 1][n - 1] < k) {
        cout << string(2 * n - 1, 'a') << '\n';
        return 0;
    }
    int sum = -1;
    vector<pii> best;
    rep(i, 0, n) rep(j, 0, n) {
        if(i + j > sum && i + j - maxA[i][j] <= k) {
            sum = i + j;
            best.clear();
            best.emplace_back(i, j);
        }else if(i + j == sum && i + j - maxA[i][j] <= k) {
            best.emplace_back(i, j);
        }
    }
    assert(!best.empty());
    string ans(sum, 'a');
    vector<pii> nxt;
    rep(i, sum, 2 * n - 1) {
        char ch = 'z' + 1;
        for(pii &pa : best) {
            int i, j;
            tie(i, j) = pa;
            if(nxt.empty() || s[i][j] < ch) {
                nxt.clear();
                ch = s[i][j];
                if(i + 1 < n) nxt.emplace_back(i + 1, j);
                if(j + 1 < n) nxt.emplace_back(i, j + 1);
            }else if(!nxt.empty() && s[i][j] == ch) {
                if(i + 1 < n) nxt.emplace_back(i + 1, j);
                if(j + 1 < n) nxt.emplace_back(i, j + 1);
            }
        }
        sort(all(nxt));
        nxt.erase(unique(all(nxt)), nxt.end());
        ans.push_back(ch);
        nxt.swap(best);
        nxt.clear();
    }
    cout << ans << '\n';
}