#include <bits/stdc++.h>
#define pb push_back
#define ll long long

using namespace std;


int main()
{
    string s;
    getline(cin, s);
    int k = 0;
    for (int i = 0; i < (int)s.size(); i++)
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'u' || s[i] == 'o')
            k++;
    if (k != 5)
    {
        cout << "NO";
        return 0;
    }

    getline(cin, s);
    k = 0;
    for (int i = 0; i < (int)s.size(); i++)
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'u' || s[i] == 'o')
            k++;
    if (k != 7)
    {
        cout << "NO";
        return 0;
    }

    getline(cin, s);
    k = 0;
    for (int i = 0; i < (int)s.size(); i++)
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'u' || s[i] == 'o')
            k++;
    if (k != 5)
    {
        cout << "NO";
        return 0;
    }
    cout << "YES";
    return 0;
}