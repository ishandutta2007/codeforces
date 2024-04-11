#include <iostream>
using namespace std;

int main()
{
    string s;
    bool b[26];
    for (int i=0; i<26; i++) b[i]=false;
    cin >> s;
    for (int i=0; i<s.length(); i++)
    {
        b[s[i]-'a']=true;
    }
    int n=0;
    for (int i=0; i<26; i++)
        if (b[i]) n++;
    if (n%2==0)
    {
        cout << "CHAT WITH HER!" << endl;
    }
    else
    {
        cout << "IGNORE HIM!" << endl;
    }
}