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
    int n;
    ll t;
    string s;
    cin >> n >> t >> s;
    vector<ll> cnt(60, 0);
    rep(i, 0, n - 2) {
        int val = s[i] - 'a';
        t -= (1LL << val);
        cnt[val + 1]++;
    }
    t -= (1LL << (s.back() - 'a'));
    t += (1LL << (s[n - 2] - 'a'));
    t = -t;
    if(t < 0) {
        cout << "No\n";
        return 0;
    }
    rep(i, 0, 60) {
        if(t >> i & 1) {
            if(cnt[i] == 0) {
                cout << "No\n";
                return 0;
            }
            cnt[i]--;
        }
        if(i < 59) cnt[i + 1] += cnt[i] / 2;
    }
    cout << "Yes\n";
}