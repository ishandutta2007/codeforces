
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) {
        int n; string s;
        cin >> n >> s;
        sort(s.begin(), s.end());
        cout << s << '\n';
    }
}