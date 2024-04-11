
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

// no way this will pass

const int N = 1e5 + 5;
string s;
int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> s;
    n = s.length();
    vector<pii> ve;
    for(int i = n - 1; i >= 0; i--) {
        while(i >= 0 && s[i] == '0') i--;
        if(i < 0) break;
        int k = i + 1;
        while(i >= 0 && s[i] == '1') i--;
        i++;
        int dp0 = 0, dp01 = 0, dp1 = k - i;
        int amt = k - i;
        for(int j = k; j < n; j++) {
            int tmp0 = dp0, tmp01 = dp01, tmp1 = dp1;
            if(s[j] == '0') {
                tmp0 = 1 + dp0;
            }else {
                tmp1 = 1 + dp1;
                tmp01 = 1 + max(dp01, dp0);
            }
            dp0 = tmp0;
            dp01 = tmp01;
            dp1 = tmp1;
            amt = min(amt, dp1 - max(dp0, dp01));
        }
        ve.emplace_back(i, amt);
    }
    for(auto &p : ve) {
        int i, amt;
        tie(i, amt) = p;
        rep(j, 0, amt) {
            s[i + j] = '0';
        }
    }
    cout << s << '\n';
}