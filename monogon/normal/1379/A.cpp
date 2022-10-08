
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
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        string s1 = "abacaba";
        string s2;
        cin >> n >> s2;
        int idx = -1;
        int cnt = 0;
        rep(i, 0, n - (int) s1.length() + 1) {
            bool flag = true;
            rep(j, 0, (int) s1.length()) {
                flag &= (s2[i + j] == '?' || s2[i + j] == s1[j]);
            }
            flag &= (i - 4 < 0 || s2.substr(i - 4, 4) != "abac");
            flag &= (i - 6 < 0 || s2.substr(i - 6, 6) != "abacab");
            flag &= (i + 7 + 4 > n || s2.substr(i + 7, 4) != "caba");
            flag &= (i + 7 + 6 > n || s2.substr(i + 7, 6) != "bacaba");
            if(flag) {
                idx = i;
            }
            cnt += (s2.substr(i, 7) == s1);
        }
        if(idx == -1 || cnt > 1) {
            cout << "No\n";
        }else if(cnt > 0) {
            rep(i, 0, n) {
                if(s2[i] == '?') s2[i] = 'z';
            }
            cout << "Yes\n" << s2 << '\n';
        }else {
            cout << "Yes\n";
            rep(i, 0, (int) s1.length()) {
                s2[idx + i] = s1[i];
            }
            rep(i, 0, n) {
                if(s2[i] == '?') s2[i] = 'z';
            }
            cout << s2 << '\n';
        }
    }
}