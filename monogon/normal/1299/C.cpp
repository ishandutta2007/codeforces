
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 1e6 + 5;
int n;
ll a[N];
stack<pair<ll, int>> st;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = n - 1; i >= 0; i--) {
        ll sum = a[i];
        int cnt = 1;
        while(!st.empty()) {
            auto [x, j] = st.top();
            if((sum + x) * cnt < sum * (cnt + j)) {
                sum += x;
                cnt += j;
                st.pop();
            }else break;
        }
        st.push({sum, cnt});
    }
    cout << fixed << setprecision(10);
    while(!st.empty()) {
        auto p = st.top(); st.pop();
        double D = 1.0 * p.first / p.second;
        for(int j = 0; j < p.second; j++) {
            cout << D << '\n';
        }
    }
}