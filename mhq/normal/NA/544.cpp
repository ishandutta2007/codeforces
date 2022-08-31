#include <bits/stdc++.h>
using namespace std;
string s;
int main() {
    //freopen("input.txt", "r", stdin);
    cin >> s;
    int cnt = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'o') cnt++;
    }
    if (cnt == 0) {
        cout << "YES";
        return 0;
    }
    if (s.size() % cnt == 0 || cnt == 0) {
        cout << "YES";
    }
    else cout << "NO";
    return 0;
}