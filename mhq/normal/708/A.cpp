#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
int main() {
    //freopen("input.txt", "r", stdin);
    srand(239);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    if (s[0] != 'a') {
        int i = 0;
        while (i < s.size() && s[i] != 'a') {
            s[i]--;
            i++;
        }
        cout << s;
    }
    else {
        int i = 0;
        while (i < s.size() && s[i] == 'a') {
            i++;
        }
        if (i == s.size()) {
            s.back() = 'z';
            cout << s;
        }
        else {
            int j = i;
            while (j < s.size() && s[j] != 'a') {
                s[j]--;
                j++;
            }
            cout << s;
        }
    }
    return 0;
}