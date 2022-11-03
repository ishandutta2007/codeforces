#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int n;
    string s;
    cin >> n >> s;
    if(n == 12)
    {
        int h = (s[0]-'0')*10 + (s[1]-'0');
        int m = (s[3]-'0')*10 + (s[4]-'0');
        if(m >= 60)
            s[3] = '5';
        if(h == 0)
            s[0] = '1';
        else if (h > 12)
            s[0] =(s[1] == '0'?'1':'0');
    }
    else if (n == 24)
    {
        int h = (s[0]-'0')*10 + (s[1]-'0');
        int m = (s[3]-'0')*10 + (s[4]-'0');
        if(m >= 60)
            s[3] = '5';
        if (h >= 24)
            s[0] = '0';
    }
    cout << s;
}