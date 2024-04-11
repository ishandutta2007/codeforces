
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;

int t;
string s, s2;
int n, m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> s >> s2;
        n = s.length();
        m = s2.length();
        int i = 0;
        bool flag = true;
        rep(j, 0, m) {
            if(i < n && s[i] == s2[j]) i++;
            else if(i == 0 || s[i - 1] != s2[j]) {
                flag = false;
                break;
            }
        }
        flag &= (i == n);
        cout << (flag ? "YES" : "NO") << '\n';
    }
}