#include <iostream>
#include <string.h>
using namespace std;
int main()
{
    int i,x;
    string s;
    cin >> s;
    for (i=1;i<s.size()-3;i++)
    {
        if (s[i]=='d' && s[i+1]=='o' && s[i+2]=='t')
        {
            s[i]='.';
            for (x=i+1;x<s.size()-2;x++)
            s[x]=s[x+2];
            s.resize(s.size()-2);
        }
    }
    for (i=1;i<s.size()-2;i++)
    {
        if (s[i]=='a' && s[i+1]=='t')
        {
            s[i]='@';
            for (x=i+1;x<s.size()-1;x++)
            s[x]=s[x+1];
            s.resize(s.size()-1);
            break;
        }
    }
    cout << s;
}