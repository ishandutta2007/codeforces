#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define all(a) a.begin(), a.end()

const int N = (1<<20);
const int mod = 1e9+7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--) {
        string s; cin>> s;
        int n = s.size();
        if (n == 2) {
            cout << s[1] << endl;
        } else {
            sort(all(s));
            cout << s[0] << endl;
        }
    }
}