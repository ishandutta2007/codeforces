#include <iostream>
using namespace std;

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    for (int i=0; i<s1.length(); i++)
    {
        if (s1[i]<='Z') s1[i]=s1[i]-'A'+'a';
    }
    for (int i=0; i<s2.length(); i++)
    {
        if (s2[i]<='Z') s2[i]=s2[i]-'A'+'a';
    }
    int c = s1.compare(s2);
    if (c<0) cout << -1 << endl;
    else if (c==0) cout << 0 << endl;
    else cout << 1 << endl;
}