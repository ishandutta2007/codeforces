
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

struct dsu {
    vector<int> a;
    dsu(int n) : a(n, -1) {}
    int find(int x) {
        return a[x] < 0 ? x : a[x] = find(a[x]);
    }
    int size(int x) {
        return -a[find(x)];
    }
    bool join(int x, int y) {
        if((x = find(x)) == (y = find(y))) return false;
        if(a[x] > a[y]) swap(x, y);
        a[x] += a[y];
        a[y] = x;
        return true;
    }
};

void solve() {
    int n;
    string s;
    cin >> n >> s;
    vector<bool> from(26), to(26);
    vector<char> follows(26);
    dsu D(26);
    rep(i, 0, n) {
        if(!from[s[i] - 'a']) {
            for(int j = 0; j < 26; j++) {
                if(!to[j] && (D.find(j) != D.find(s[i] - 'a') || D.size(j) == 26)) {
                    to[j] = true;
                    from[s[i] - 'a'] = true;
                    follows[s[i] - 'a'] = 'a' + j;
                    D.join(s[i] - 'a', j);
                    break;
                }
            }
        }
        cout << follows[s[i] - 'a'];
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}