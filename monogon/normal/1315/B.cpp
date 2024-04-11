
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 1e5 + 5;
int t, a, b, n, p;
string s;
ll ans[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> a >> b >> p >> s;
        n = s.length();
        ans[n - 1] = 0;
        int idx[2] = {-1, -1};
        idx[s[n - 1] - 'A'] = n - 1;
        for(int i = n - 2; i >= 0; i--) {
            int j = idx[!(s[i] - 'A')];
            ans[i] = (s[i] == 'A' ? a : b) + (j == -1 ? 0 : ans[j]);
            idx[s[i] - 'A'] = i;
        }
        for(int i = 0; i < n; i++) {
            if(ans[i] <= p) {
                cout << (i + 1) << endl;
                break;
            }
        }
    }
}