#include <bits/stdc++.h>
using namespace std;
const int maxN = (int)1e5 + 10;
int n;
string s;
string ss;
string t;
int num1[30];
int num2[30];
int step[2005];
void shift(string &t, int x) {
    string nt;
    for (int i = n - 1; i >= n - x; i--) {
        nt += t[i];
    }
    for (int i = 0; i < n - x; i++) nt += t[i];
    t = nt;
}
int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    cin >> s >> t;
    for (int i = 0; i < s.size(); i++) {
        num1[s[i] - 'a']++;
        num2[t[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
        if (num1[i] != num2[i]) {
            cout << -1;
            return 0;
        }
    }
    ss = t;
    for (int i = 0; i < n; i++) {
        step[n - 1 - i] = ss[ss.size() - 1] - 'a';
        string new_ss;
        for (int i = 0; i + 1 < ss.size(); i++) {
            new_ss += ss[i];
        }
        reverse(new_ss.begin(), new_ss.end());
        ss = new_ss;
    }
    vector < int > ans;
    string cur_s = s;
    for (int i = 0; i < n; i++) {
        int ind = -1;
        for (int j = i; j < n; j++) {
            if ((cur_s[j] - 'a') == step[i]) {
                ind = j;
                break;
            }
        }
        shift(cur_s, n - 1 - ind);
        ans.push_back(n - 1 - ind);
        shift(cur_s, ind - i + 1);
        ans.push_back(ind - i + 1);
        shift(cur_s, i);
        ans.push_back(i);
    }
    //cout << cur_s << " " << t << endl;
    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
    return 0;
}