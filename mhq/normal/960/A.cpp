#include <bits/stdc++.h>
using namespace std;
string s;
int cnt1, cnt2, cnt3;
int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        for (int j = i + 1; j < s.size(); j++) {
            if (s[i] > s[j]) {
                cout << "NO";
                return 0;
            }
        }
    }
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'a') cnt1++;
        else if (s[i] == 'b') cnt2++;
        else cnt3++;
    }
    if (cnt1 == 0 || cnt2 == 0) cout << "NO";
    else if ((cnt1 == cnt3) || (cnt2 == cnt3)) cout << "YES";
    else cout << "NO";
    return 0;
}