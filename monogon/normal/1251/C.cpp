
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int q;
string s, t1, t2;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> q;
    while(q--) {
        cin >> s;
        string t[2];
        for(char c : s) {
            t[(c - '0') & 1].push_back(c);
        }
        merge(t[0].begin(), t[0].end(), t[1].begin(), t[1].end(), s.begin());
        cout << s << endl;
    }
}