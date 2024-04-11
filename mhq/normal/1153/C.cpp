#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n, m, h;
void bad() {
    cout << ":(";
    exit(0);
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    srand(time(0));
    string s;
    int n;
    cin >> n;
    cin >> s;
    int cur_bal = 0;
    int que = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') cur_bal++;
        else if (s[i] == ')') cur_bal--;
        else que++;
    }
    if ((cur_bal + que) % 2 != 0) bad();
    int x = (que - cur_bal) / 2;
    if (x < 0 || x > que) bad();
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '?')  {
            if (x != 0) {
                s[i] = '(';
                x--;
            }
            else {
                s[i] = ')';
            }
        }
    }
    int bal = 0;
    for (int j = 0; j < s.size(); j++) {
        if (s[j] == '(') bal++;
        else bal--;
        if (bal < 0) bad();
        if (j != s.size() - 1 && bal == 0) bad();
    }
    if (bal != 0) bad();
    cout << s;
    return 0;
}