
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

// check each pair of words? why not
// segment [a, b] of words
// k * len new letters
// k * (len - 1) spaces deleted
// k * sum of lengths deleted
// tot + k * len - k * (len - 1) - k * sum
// tot + k - k * sum

const int N = 305;
int n;
string w[N];
bool b[N][N];
int kmp[N];

void makekmp(int idx) {
    kmp[idx] = 0;
    int i = idx + 1, j = 0;
    while(i < n) {
        if(b[i][idx + j]) kmp[i++] = ++j;
        else if(j == 0) kmp[i++] = 0;
        else j = kmp[j - 1];
    }
}
vi kmpfind(int idx, int len) {
    int i = idx, j = 0;
    vi v;
    while(i < n) {
        if(b[i][idx + j]) i++, j++;
        if(j == len) {
            v.push_back(i - j);
            j = 0;
        }else if (i < n && !b[i][idx + j]) {
            if(j == 0) i++;
            else j = kmp[j - 1];
        }
    }
    return v;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    int tot = n - 1;
    rep(i, 0, n) {
        cin >> w[i];
        tot += w[i].length();
    }
    rep(i, 0, n) rep(j, i, n) {
        b[i][j] = b[j][i] = (w[i] == w[j]);
    }
    int ans = tot;
    rep(i, 0, n) {
        makekmp(i);
        int sum = 0;
        for(int len = 1; i + len <= n; len++) {
            sum += w[i + len - 1].length();
            int k = sz(kmpfind(i, len));
            if(k >= 2) {
                ans = min(ans, tot + k - k * sum);
            }
        }
    }
    cout << ans << endl;
}