#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    string s, t;
    cin >> s;
    t = s;
    reverse(t.begin(), t.end());
    t += s;
    cout << t << endl;
    return 0;
}