#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

int main()
{
    string s;
    string a = "", b = "";
    cin >> s;
    for (int i = 0; i < s.size() / 2; i++)
        a = a + s[i];
    int k = 1;
    for (int i = s.size()-1; i >= (s.size()-1)/2+1; i--)
        b = b + s[i];
    int c = 0;

    for (int i = 0; i < a.size(); i++)
        if (a[i] != b[i])
            c++;
    //cout << a << ' '<< b;
    if (c == 1)
        cout << "YES";
    else
        if (c == 0 & s.size()%2 == 1)
            cout << "YES";
        else
            cout << "NO";
    return 0;
}