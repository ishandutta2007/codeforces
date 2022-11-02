#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s, t = "CODEFORCES";
    cin >> s;

    int sn = s.size(), tn = t.size();

    int l = 0, r = tn - 1;

    for (int i = 0; i < sn && l < tn && s[i] == t[l]; i++, l++);
    for (int j = sn - 1; j >= 0 && r >= 0 && s[j] == t[r]; j--, r--);

    cout << ((l > r) ? "YES" : "NO") << endl;
    return 0;
}