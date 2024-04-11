#include <iostream>
using namespace std;

bool capsLock(string s)
{
    for (int i=1; i<s.length(); i++)
    {
        if (s[i]>='a') return false;
    }
    return true;
}

int main()
{
    string s;
    cin >> s;
    if (capsLock(s))
    {
        if (s[0]<='Z') s[0]=s[0]-'A'+'a';
        else s[0]=s[0]-'a'+'A';
        for (int i=1; i<s.length(); i++)
        {
            s[i]=s[i]-'A'+'a';
        }
        cout << s << endl;
    }
    else cout << s << endl;
}