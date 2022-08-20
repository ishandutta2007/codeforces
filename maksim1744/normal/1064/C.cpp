/*
    19.10.2018 16:55:50
*/

#include <bits/stdc++.h>

using namespace std;

const bool debug = true;

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    string s1;
    cin >> s1;
    vector< int > s(26, 0);
    for (int i = 0; i < s1.length(); ++i) {
        ++s[s1[i] - 'a'];
    }
    int sm = 0;
    int i1 = 0, i2 = 1;
    vector< int > ans;
    for (int i = 0; i < 26; ++i) {
        for (int j = 0; j < s[i]; ++j) {
            ans.push_back(i);
        }
    }
    for (auto item : ans) {
        cout << (char)(item + 'a');
    }
    cout << '\n';
    return 0;
}