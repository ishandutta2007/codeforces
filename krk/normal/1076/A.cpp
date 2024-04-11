#include <bits/stdc++.h>
using namespace std;

int n;
string s;

int main()
{
    cin >> n;
    cin >> s;
    for (int i = 0; i < s.length(); i++)
        if (i + 1 >= s.length() || s[i] > s[i + 1]) {
            s.erase(s.begin() + i);
            cout << s << endl;
            break;
        }
    return 0;
}