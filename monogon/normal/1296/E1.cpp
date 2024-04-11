
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 205;
int n;
string s, v[2];
bool b[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> s;
    for(int i = 0; i < n; i++) {
        if(v[0].empty() || v[0].back() <= s[i]) {
            v[0].push_back(s[i]);
            b[i] = 0;
        }else if(v[1].empty() || v[1].back() <= s[i]) {
            v[1].push_back(s[i]);
            b[i] = 1;
        }else {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    for(int i = 0; i < n; i++) {
        cout << b[i];
    }
    cout << endl;
}