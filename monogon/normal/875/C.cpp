
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

// if two words have different first character, we must
// change the first character but not the second.
// "must be capitalized" vs "must be lowercase" bitmask of length 2
// with same first characters, must be a segment

// a < b in order. We can capitalize a, or capitalize neither, or capitalize both
// B => A

// for each adjacent pair of strings, find first character they differ
// if first string prefix of second, all is fine
// if first string contains second strictly as a prefix, answer NO
// otherwise, if a > b => a is capitalized and b is not
// if a < b => b is capitalized only if a is. add edge b -> a

// create set of characters that must be capitalized, and those that must not
// mark all nodes reachable from nodes that must be capitalized
// if we can reach a node that must be lowercase, we answer NO
// otherwise, the nodes marked capitalized suffices.

const int N = 1e5 + 5;
int n, m, l[N];
vi s[N], adj[N];
bool lower[N], upper[N], vis[N];

void dfs(int x) {
    vis[x] = upper[x] = true;
    for(int y : adj[x]) {
        if(!vis[y]) {
            dfs(y);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    rep(i, 0, n) {
        cin >> l[i];
        s[i].assign(l[i], 0);
        rep(j, 0, l[i]) {
            cin >> s[i][j];
        }
    }
    rep(i, 1, n) {
        int j = 0;
        while(j < l[i] && j < l[i - 1] && s[i][j] == s[i - 1][j]) j++;
        if(j == l[i] || j == l[i - 1]) {
            if(j == l[i] && l[i - 1] > l[i]) {
                cout << "No\n";
                return 0;
            }
        }else if(s[i - 1][j] > s[i][j]) {
            upper[s[i - 1][j]] = true;
            lower[s[i][j]] = true;
        }else {
            adj[s[i][j]].push_back(s[i - 1][j]);
        }
    }
    rep(i, 1, m + 1) {
        if(upper[i] && !vis[i]) {
            dfs(i);
        }
    }
    vi cap;
    rep(i, 1, m + 1) {
        if(upper[i] && lower[i]) {
            cout << "No\n";
            return 0;
        }else if(upper[i]) {
            cap.push_back(i);
        }
    }
    cout << "Yes\n" << sz(cap) << '\n';
    for(int x : cap) {
        cout << x << ' ';
    }
    cout << '\n';
}