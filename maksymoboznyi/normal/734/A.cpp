#include <iostream>

using namespace std;

int main()
{
    string s;
    int p;
    cin >> p;
    cin >> s;
    int d = 0, a = 0;
    for (int i = 0; i < s.size();i++)
        if (s[i] == 'A')
            a++;
            else
                d++;
    if (a > d)
        cout << "Anton";
    if (a==d)
        cout << "Friendship";
    if (a < d)
        cout << "Danik";
    return 0;
}