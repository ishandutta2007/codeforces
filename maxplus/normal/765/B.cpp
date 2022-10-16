#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

int main()
{
    string s;
    set<char> S;
    string t;
    cin >> s;
    for (char i: s)
        if (!S.count(i))
            S.insert(i), t += i;
    s = "";
    for (char i = 'a'; i <= 'z'; ++i)
        s += i;
    if (t == s.substr(0, t.size()))
        cout << "YES";
    else
        cout << "NO";
    return 0;
}