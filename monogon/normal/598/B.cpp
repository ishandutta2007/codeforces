
#include <bits/stdc++.h>

#define ll long long

using namespace std;

string s, s1;
int n, m, l, r, k;

int main() {
    cin >> s;
    n = s.length();
    cin >> m;
    while(m--) {
        cin >> l >> r >> k;
        s1 = s.substr(l - 1, r - l + 1);
        for(int i = l; i <= r; i++) {
            s[i - 1] = s1[((i - l - k) % (r - l + 1) + (r - l + 1)) % (r - l + 1)];
        }
    }
    cout << s << endl;
}