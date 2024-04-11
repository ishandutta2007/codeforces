
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 5e4 + 5;
int n, m, cnt;
string s;
ll a[N], b[N], cost;
priority_queue<pair<ll, int>> Q;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> s;
    n = s.length();
    for(int i = 0; i < n; i++) {
        if(s[i] == '?') {
            cin >> a[i] >> b[i];
            cnt--;
            Q.emplace(b[i] - a[i], i);
            cost += b[i];
            s[i] = ')';
        }else if(s[i] == '(') {
            cnt++;
        }else {
            cnt--;
        }
        if(cnt < 0) {
            if(Q.empty()) {
                cout << -1 << endl;
                return 0;
            }
            int j = Q.top().second;
            Q.pop();
            cost += a[j] - b[j];
            cnt += 2;
            s[j] = '(';
        }
    }
    if(cnt != 0) {
        cout << -1 << endl;
        return 0;
    }
    cout << cost << endl << s << endl;
}