#include <bits/stdc++.h>

using namespace std;
int cnt[50];
string s;
vector < int > all;
int main() {
    //freopen("input.txt", "r", stdin);
    //calc();
    ios_base::sync_with_stdio(false);
    cin >> s;
    if (s.size() < 4) {
        cout << "No";
        return 0;
    }
    for (int i = 0; i < s.size(); i++) cnt[s[i] - 'a']++;
    int get = 0;
    for (int i = 0; i < 26; i++) {
        if (cnt[i] != 0) {
            get++;
            all.push_back(cnt[i]);
        }
    }
    if (get > 4) {
        cout << "No";
        return 0;
    }
    if (get == 4) {
        cout << "Yes";
        return 0;
    }
    if (get == 3) {
        cout << "Yes";
        return 0;
    }
    if (get == 1) {
        cout << "No";
        return 0;
    }
    if (get == 2) {
        if (all[0] == 1 || all[1] == 1) {
            cout << "No";
            return 0;
        }
        cout << "Yes";
    }
    return 0;
}