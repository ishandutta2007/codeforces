#include<bits/stdc++.h>
using namespace std;
const int N = 300000 + 5;
constexpr int mod = 998244353;
using LL = long long;
int bin[2000];
void work() {
    string s;
    cin >> s;
    int n = s.length();
    sort(s.begin(), s.end());
    if (s[0] == s[n - 1]) {
        cout << s << '\n';
        return;
    }
    int small = 0;
    for (auto x : s) {
        if (x == s[0]) small++;
        bin[x] ++;
    }
    string ans;
    for (int i = 'a'; i <= 'z'; i += 1) {
        if (bin[i] == 1) {
            char x = i;
            ans.push_back(x);
            bin[i] --;
            for (int j = 'a'; j <= 'z'; j += 1) {
                while (bin[j]) {
                    char y = j;
                    ans.push_back(y);
                    bin[j] --;
                }
            }
            cout << ans << '\n';
            return;
        }
    }
    if (small - 2 <= n - small) {
        ans.push_back(s[0]);
        ans.push_back(s[0]);
        bin[s[0]] --;
        bin[s[0]] --;
        for (int j = 'a'; j <= 'z'; j += 1) {
            char x = j;
            if (x == s[0]) continue;
            while (bin[j]) {
                ans.push_back(x);
                bin[j] --;
                if (bin[s[0]]) {
                    bin[s[0]] --;
                    ans.push_back(s[0]);
                }
            }
        }
        cout << ans << '\n';
        return;
    }
    int havc = 0;
    for (auto x : s) {
        if (x != s[0] && x != s[n - 1]) {
            havc = 1;
            break;
        }
    }
    if (!havc) {
        ans.push_back(s[0]);
        bin[s[0]] --;
        while (bin[s[n - 1]]) {
            ans.push_back(s[n - 1]);
            bin[s[n - 1]] --;
        }
        while (bin[s[0]]) {
            ans.push_back(s[0]);
            bin[s[0]] --;
        }
    }
    for (int j = s[0] + 1; j <= 'z'; j += 1) {
        char x = j;
        while (bin[j]) {
            ans.push_back(s[0]);
            bin[s[0]] --;
            ans.push_back(x);
            bin[j] --;
            while (bin[s[0]]) {
                ans.push_back(s[0]);
                bin[s[0]] --;
            }
            for (int k = j + 1; k <= 'z'; k += 1) {
                if (bin[k]) {
                    char y = k;
                    ans.push_back(k);
                    bin[k] --;
                    break;
                }
            }
            if (!bin[s[0]]) {
                break;
            }
        }
        if (!bin[s[0]]) break;
    }
    for (int j = s[0] + 1; j <= 'z'; j += 1) {
        char x = j;
        while (bin[j]) {
            ans.push_back(x);
            bin[j] --;
        }
    }
    cout << ans << '\n';
    return;
}
int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        work();
        for (int i = 'a'; i <= 'z'; i += 1) bin[i] = 0;
    }

}
/*

*/