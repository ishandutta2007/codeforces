#include <algorithm>
#include <iostream>
#define all(a) a.begin(), a.end()

using namespace std;

int main()
{
    string s1, s2, t;
    cin >> s1 >> t;
    reverse(all(t)), s1 += t;
    cin >> s2 >> t;
    reverse(all(t)), s2 += t;
    for (int i = 0; i < 4; ++i)
        if (s1[i] == 'X')
        {
            s1 = s1.substr(0, i) + s1.substr(i + 1, s1.size());
            break;
        }
    for (int i = 0; i < 4; ++i)
        if (s2[i] == 'X')
        {
            s2 = s2.substr(0, i) + s2.substr(i + 1, s2.size());
            break;
        }
    s1 += s1;
    s2 += s2;
    while (s1[0] != 'A')
        s1 = s1.substr(1, s1.size());
    while (s2[0] != 'A')
        s2 = s2.substr(1, s2.size());
    for (int i = 0; i < 3; ++i)
        if (s1[i] != s2[i])
            return cout << "NO\n", 0;
    cout << "YES\n";
    return 0;
}