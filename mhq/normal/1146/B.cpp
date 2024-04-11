#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
string s;
void bad() {
    cout << ":(";
    exit(0);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
   //freopen("input.txt", "r", stdin);
    cin >> s;
    int cntA = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'a') cntA++;
    }
    if (s.size() % 2 != cntA % 2) {
        bad();
    }
    string t;
    int need = (s.size() + cntA) / 2;
    for (int i = 0; i < need; i++) t += s[i];
    string f;
    for (int i = 0; i < t.size(); i++) {
        if (t[i] == 'a') {
            continue;
        }
        f += t[i];
    }
    if (t + f == s) {
        cout << t;
    }
    else bad();
    return 0;
}