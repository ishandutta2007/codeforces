#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;
int main()
{
    long long ans=0;
    string s;
    cin >> s;
    for (int i=1;i<s.size();i++)
    {
        string tmp(1,s[i-1]);
        tmp+=s[i];
        if (atoi(tmp.c_str())%4==0)
        ans+=i;
    }
    for (int i=0;i<s.size();i++)
    {
        if (s[i]=='0' || s[i]=='4' || s[i]=='8')
        ans++;
    }
    cout << ans;
}