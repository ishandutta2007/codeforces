
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 150'005;
int t, n;
string s;
int dp[N];
set<int> S;

bool match(const string &s, const string &t, int i) {
    int j = i + t.length();
    if(i < 0 || i > s.length()) return false;
    for(int k = i; k < j; k++) {
        if(s[k] != t[k - i]) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> s;
        S.clear();
        n = s.length();
        for(int i = 0; i < n; i++) {
            if((s[i] == 'o' && match(s, "twone", i - 2)) ||
                    (s[i] == 'n' && !match(s, "twone", i - 3) && match(s, "one", i - 1)) || 
                    (s[i] == 'w' && !match(s, "twone", i - 1) && match(s, "two", i - 1))) {
                S.insert(i);
            }
        }
        cout << S.size() << endl;
        for(int x : S) {
            cout << (x + 1) << " ";
        }
        cout << endl;
    }
}