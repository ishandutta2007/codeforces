
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 1005;
int t, n;
int x[N], y[N];
vector<pair<int, int>> v;
string ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        v.clear();
        for(int i = 0; i < n; i++) {
            cin >> x[i] >> y[i];
            v.emplace_back(x[i] + y[i], i);
        }
        sort(v.begin(), v.end());
        ans.clear();
        int prevx = 0;
        int prevy = 0;
        for(int i = 0; i < n; i++) {
            int idx = v[i].second;
            if(i > 0 && (v[i].first == v[i - 1].first || prevx > x[idx] || prevy > y[idx])) {
                cout << "NO" << endl;
                goto endloop;
            }
            for(int j = 0; j < x[idx] - prevx; j++) ans.push_back('R');
            for(int j = 0; j < y[idx] - prevy; j++) ans.push_back('U');
            prevx = x[idx];
            prevy = y[idx];
        }
        cout << "YES" << endl << ans << endl;
        endloop:;
    }
}