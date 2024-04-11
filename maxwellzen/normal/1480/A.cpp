#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pi pair<int, int>
#define mp make_pair
#define pb push_back
#define vi vector<int>
#define F first
#define S second
int t;
string s;

void solve() {
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        if (i%2==0) {
            if (s[i]=='a') s[i]='b';
            else s[i]='a';
        } else {
            if (s[i]=='z') s[i]='y';
            else s[i]='z';
        }
    }
    cout << s << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--) {
        solve();
    }
}