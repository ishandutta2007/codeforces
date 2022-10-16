#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    string s;
    cin >> s;
    int a = 0, b = 0;
    for (int i = 0; i < s.size(); ++i) if (s[i] == 'a') ++a; else ++b;
    cout << a + min(a - 1, b) << endl;
    return 0;
}