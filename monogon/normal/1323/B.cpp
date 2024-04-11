
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 40'005;
int n, m;
ll k;
int a[N], b[N];
vector<int> va, vb;

void process(int *arr, int n, vector<int> &v) {
    int cnt = 0;
    for(int i = 0; i <= n; i++) {
        if(i == n || arr[i] == 0) {
            for(int j = 1; j <= cnt; j++) {
                v.push_back(j);
            }
            cnt = 0;
        }else {
            cnt++;
        }
    }
    sort(v.begin(), v.end());
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < m; i++) {
        cin >> b[i];
    }
    process(a, n, va);
    process(b, m, vb);
    ll ans = 0;
    for(int d = 1; d <= n && d <= k; d++) {
        if(k % d == 0) {
            int i = lower_bound(va.begin(), va.end(), d) - va.begin();
            int j = lower_bound(vb.begin(), vb.end(), k / d) - vb.begin();
            ans += ((ll) va.size() - i) * ((ll) vb.size() - j);
        }
    }
    cout << ans << endl;
}