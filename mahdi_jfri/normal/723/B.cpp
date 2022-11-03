#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll res;
string s;
int _min[10];
bool x;
int main()
{
    int n;
    cin >> n;
    cin >> s;
    for(int i = 0; i < n; i++)
    {
        if(s[i] == '(')
        {
            x = 1;
            continue;
        }
        if(s[i] == ')')
        {
            x = 0;
            continue;
        }
        if(s[i] == '_')
            continue;
        int a = s.find("_" , i);
        int b = s.find("(", i);
        int c = s.find(")", i);
        if(a == string::npos)
            a = 1e6;
        if(b == string::npos)
            b = 1e6;
        if(c == string::npos)
            c = 1e6;
        int y = min(a,min(b,c));
        if(x)
        {
            res++;
            i = y - 1;
            continue;
        }
        if(y == 1e6)
            y = n;
        _min[x] = max(_min[x],y - i);
        if(y != string::npos)
            i = y - 1;
    }
    cout << _min[0] << " " << res;
}