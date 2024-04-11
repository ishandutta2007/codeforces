#include <bits/stdc++.h>
using namespace std;
#define ll long long
string s;
ll ii;
int strToInt(string s)
{
    int n;
    istringstream ss(s);
    ss >> n;
    return n;
}
int main()
{
    cin >> s;
    ii = s.find("e");
    string ss=s.substr(ii+1);
    ll x = strToInt(ss);
    ll y = ii-1;
    while(y > -1 && s[y] == '0')
    {
        y--;
        if(s[y] == '.')
            break;
    }
    ii = y;
    if(ii == -1)
    {
        cout << 0;
        return 0;
    }
    else
        ii++;
    for(ll i = 0 ; i < ii; i++)
    {
        if(s[i] != '.')
            cout << s[i];
        if(s[i] == '.')
        {
            i++;
            x+=i;
            while(i < x && i < ii)
            {
                cout << s[i];
                i++;
            }
            while(i < x)
            {
                cout<< 0;
                i++;
            }
            if(i < ii)
                cout << '.';
            i--;
        }
    }
}