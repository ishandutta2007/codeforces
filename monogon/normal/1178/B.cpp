
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int MAX_N = 1e6 + 5;
int n;
string s;
int w[MAX_N];

int main() {
    ios::sync_with_stdio(false);
    cin >> s;
    n = s.length();
    for(int i = 1; i < n; i++) {
        w[i + 1] = w[i] + (s[i] == 'v' && s[i - 1] == 'v');
    }
    int w2 = 0;
    ll tot = 0;
    for(int i = n - 2; i >= 2; i--) {
        w2 += (s[i] == 'v' && s[i + 1] == 'v');
        if(s[i] == 'o') {
            tot += ((ll) w[i]) * ((ll) w2);
        }
    }
    cout << tot << endl;
}