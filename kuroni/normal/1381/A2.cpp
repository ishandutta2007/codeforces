#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n, te;
vector<int> fr, ba;
string s, t;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> te;
    while (te--) {
        fr.clear(); ba.clear();
        cin >> n >> s >> t;
        for (int i = 1; i < n; i++) {
            if (s[i] != s[i - 1]) {
                fr.push_back(i);
            }
            if (t[i] != t[i - 1]) {
                ba.push_back(i);
            }
        }
        if (s[n - 1] != t[n - 1]) {
            fr.push_back(n);
        }
        cout << fr.size() + ba.size() << '\n';
        for (int v : fr) {
            cout << v << " ";
        }
        reverse(ba.begin(), ba.end());
        for (int v : ba) {
            cout << v << " ";
        }
        cout << '\n';
    }
}