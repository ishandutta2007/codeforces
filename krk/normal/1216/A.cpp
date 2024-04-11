#include <bits/stdc++.h>
using namespace std;

int n;
string s;
int res;

int main()
{
    cin >> n;
    cin >> s;
    for (int i = 0; i < s.length(); i += 2)
        if (s[i] == s[i + 1]) {
            res++;
            if (s[i] == 'a') s[i] = 'b';
            else s[i] = 'a';
        }
    cout << res << endl;
    cout << s << endl;
    return 0;
}