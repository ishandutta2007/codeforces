#include <bits/stdc++.h>
using namespace std;

int n, x, y;
string s;
int res;

int main()
{
    cin >> n >> x >> y;
    cin >> s;
    for (int i = 1; i <= x; i++) {
        char nd = i == y + 1? '1': '0';
        res += s[int(s.length()) - i] != nd;
    }
    cout << res << endl;
    return 0;
}