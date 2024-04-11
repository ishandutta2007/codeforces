#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;

string s;
int n, m, k;
int num[105], sgn[105];

int main() {
    getline(cin, s);
    for (int i = 0; i < s.length(); i++)
        if ('0' <= s[i] && s[i] <= '9') {
            n = atoi(s.substr(i).c_str());
            break;
        }

    sgn[m++] = 1;
    for (int i = 1; s[4 * i - 2] != '='; i++)
        sgn[m++] = s[4 * i - 2] == '+' ? 1 : -1;

    for (int i = 0; i < m; i++) {
        num[i] = sgn[i] == 1 ? n : 1;
        k += num[i] * sgn[i];
    }

    if (k < n) {
        cout << "Impossible\n";
        return 0;
    }

    for (int i = 0; i < m; i++) {
        if (sgn[i] == 1) {
            while (k > n && num[i] > 1) num[i]--, k--;
        } else {
            while (k > n && num[i] < n) num[i]++, k--;
        }
    }

    if (n != k) cout << "Impossible\n";
    else {
        cout << "Possible\n";
        int cnt = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '?') cout << num[cnt++];
            else cout << s[i];
        }
    }
}