#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    string s;
    int lst, lb, bal = 0, endbal = 0;
    cin >> s;
    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == '#')
        {
            lst = i;
            lb = bal - 1;
        }
        if (s[i] == '(')
            bal++;
        else
            bal--;
        if (bal < 0)
            cout << "-1", exit(0);
    }
    for (int i = s.size() - 1; i > lst; --i)
    {
        if (s[i] == '(')   endbal--;
        else               endbal++;
        if (endbal < 0)
            cout << "-1", exit(0);
    }
    if (bal > lb)
        cout << "-1", exit(0);
    for (int i = 0; i < lst; ++i)
        if (s[i] == '#')
            cout << "1\n";
    cout << bal + 1;
    return 0;
}