#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    string s, t;
    bool chk = false;
    cin >> s;
    t = s;
    for (int i = 1; i < s.size() / 2; i++)
        if (s[i] != s[i - 1])
            chk = true;
    if (!chk)
        return cout << "Impossible", 0;
    for (int i = 1; i < s.size(); i++)
    {
        t = t.back() + t;
        t.pop_back();
        bool pal = (s != t);
        for (int j = 0; j < t.size() && pal; j++)
            if (t[j] != t[s.size() - j - 1])
                pal = false;
        if (pal)
            return cout << 1, 0;
    }
    cout << 2;
}