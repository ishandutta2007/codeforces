#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int n;
    string s, t;
    cin >> n >> s;
    for (int i = 0; i < s.size() - 1; i++)
        if (s[i] > s[i + 1])
        {
            cout << t << s.substr(i + 1, n - 1);
            return 0;
        }
        else
            t += s[i];
    cout << t;
}