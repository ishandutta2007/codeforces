
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 2e5 + 5;
int n;
int a[N], dp[N], trans[N], team[N];
vector<pair<int, int>> v;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        v.emplace_back(a[i], i);
    }

    sort(v.begin(), v.end());
    int range = v[n - 1].first - v[0].first;
    // trans[i] = first member of this team
    for(int i = 3; i <= n - 3; i++) {
        int p1 = v[i].first - v[i - 1].first + dp[i - 3];
        if(p1 < dp[i - 1]) {
            dp[i] = dp[i - 1];
            trans[i] = trans[i - 1];
        }else {
            dp[i] = p1;
            trans[i] = i;
        }
        dp[i] = max(v[i].first - v[i - 1].first + dp[i - 3], dp[i - 1]);
    }
    int cnt = 0;
    int t = n - 3;
    while(t >= 0) {
        cnt++;
        for(int i = trans[t]; i < t + 3; i++) {
            team[v[i].second] = cnt;
        }
        t = trans[t] - 3;
    }
    cout << (range - dp[n - 3]) << " " << cnt << endl;
    for(int i = 0; i < n; i++) {
        cout << team[i] << " ";
    }
    cout << endl;
}