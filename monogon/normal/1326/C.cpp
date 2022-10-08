
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int M = 998244353;
int n, k, p;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    vector<pair<int, int>> ve;
    for(int i = 0; i < n; i++) {
        cin >> p;
        ve.emplace_back(p, i);
    }
    sort(ve.rbegin(), ve.rend());
    vector<int> v2;
    ll sum = 0;
    for(int i = 0; i < k; i++) {
        sum += ve[i].first;
        v2.push_back(ve[i].second);
    }
    sort(v2.begin(), v2.end());
    ll ways = 1;
    for(int i = 1; i < k; i++) {
        ways = (ways * (v2[i] - v2[i - 1])) % M;
    }
    cout << sum << " " << ways << endl;
}