
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int q, n;
string s, t;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> q;
    while(q--) {
        cin >> n >> s >> t;
        vector<int> v;
        for(int i = 0; i < n; i++) {
            if(s[i] != t[i]) v.push_back(i);
        }
        if(v.size() > 2 || v.size() == 1) cout << "No" << endl;
        else if(v.size() == 0) cout << "Yes" << endl;
        else if(s[v[0]] == s[v[1]] && t[v[0]] == t[v[1]]) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}