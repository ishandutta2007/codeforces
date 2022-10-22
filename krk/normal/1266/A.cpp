#include <bits/stdc++.h>
using namespace std;

int n;
string s;

bool Check(const string &s)
{
    int sum = 0;
    bool ok = false;
    for (int i = 0; i < s.length(); i++) {
        sum += s[i] - '0';
        if (s[i] == '0' || s[i] == '5')
            if (s.length() == 1) {
                if (int(s[i] - '0') % 4 == 0)
                    ok = true;
            } else for (int j = 0; j < s.length(); j++) if (i != j)
                    if ((10 * int(s[j] - '0') + int(s[i] - '0')) % 4 == 0)
                        ok = true;
    }
    return sum % 3 == 0 && ok;
}

int main()
{
    cin >> n;
    while (n--) {
        cin >> s;
        printf("%s\n", Check(s)? "red": "cyan");
    }
    return 0;
}