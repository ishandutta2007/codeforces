
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 5e5 + 5;
int n;
ll m[N], pref[N], suf[N];

void solve(ll *arr) {
    stack<pair<ll, int>> s;
    ll sum = 0;
    for(int i = 0; i < n; i++) {
        int cnt = 1;
        while(!s.empty() && s.top().first > m[i]) {
            sum -= (s.top().first - m[i]) * s.top().second;
            cnt += s.top().second;
            s.pop();
        }
        sum += m[i];
        arr[i] = sum;
        s.emplace(m[i], cnt);
    }
}
vector<pair<ll, int>> solve2(int p) {
    vector<pair<ll, int>> s;
    for(int i = 0; i <= p; i++) {
        int cnt = 1;
        while(!s.empty() && s.back().first > m[i]) {
            cnt += s.back().second;
            s.pop_back();
        }
        s.emplace_back(m[i], cnt);
    }
    return s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> m[i];
    }
    solve(pref);
    reverse(m, m + n);
    solve(suf);
    reverse(m, m + n);
    ll ans = pref[n - 1];
    int p = n - 1;
    for(int i = 0; i < n - 1; i++) {
        ll k = pref[i] + suf[n - i - 2];
        if(k > ans) {
            ans = k;
            p = i;
        }
    }
    vector<pair<ll, int>> v1 = solve2(p);
    reverse(m, m + n);
    vector<pair<ll, int>> v2 = solve2(n - p - 2);
    reverse(v2.begin(), v2.end());
    for(auto p : v1) {
        for(int j = 0; j < p.second; j++) cout << p.first << " ";
    }
    for(auto p : v2) {
        for(int j = 0; j < p.second; j++) cout << p.first << " ";
    }
    cout << endl;
}