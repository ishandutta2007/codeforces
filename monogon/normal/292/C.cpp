
#pragma GCC optimize ("Ofast")
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

// at most 12 characters
// at most 6 dependent characters
// 10^6

const int N = 11;
int n, a[N];
vector<string> ans;
bool b[N];
bool cov[N];
vi ve;

bool check(string &s) {
    int sum = 0, cnt = 0;
    fill(cov, cov + 10, false);
    rep(i, 0, 4) {
        int x = 0;
        rep(j, 0, ve[i]) {
            int c = s[sum + j] - '0';
            if(!b[c]) return false;
            cnt += !cov[c];
            cov[c] = true;
            x = 10 * x + c;
        }
        if(x >= 256 || (s[sum] == '0' && ve[i] > 1)) {
            return false;
        }
        sum += ve[i];
    }
    return cnt == n;
}

void solve() {
    int sum = accumulate(all(ve), 0);
    int dep = (sum + 1) / 2;
    int mx = pow(10, dep);
    string s(sum, '0');
    rep(i, 0, mx) {
        int x = i;
        rep(k, 0, dep) {
            s[k] = s[sum - k - 1] = '0' + (x % 10);
            x /= 10;
        }
        if(check(s)) {
            string s2(all(s));
            int sum = 0;
            rep(j, 0, 3) {
                s2.insert(s2.begin() + j + sum + ve[j], '.');
                sum += ve[j];
            }
            ans.push_back(s2);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    rep(i, 0, n) {
        cin >> a[i];
        b[a[i]] = true;
    }
    ve.assign(4, 0);
    rep(i, 0, 81) {
        int x = i;
        rep(k, 0, 4) {
            ve[k] = ((x % 3) + 1);
            x /= 3;
        }
        solve();
    }
    cout << sz(ans) << '\n';
    for(string &s : ans) {
        cout << s << '\n';
    }
}