
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int q, n;
ll k;
string s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> q;
    while(q--) {
        cin >> n >> k >> s;
        vector<int> v;
        for(int i = 0; i < n; i++) {
            if(s[i] == '0') v.push_back(i);
        }
        fill(s.begin(), s.end(), '1');
        int m = v.size();
        for(int i = 0; i < m; i++) {
            int dist = min((ll) (v[i] - i), k);
            k -= dist;
            v[i] -= dist;
            s[v[i]] = '0';
        }
        cout << s << endl;
    }
}