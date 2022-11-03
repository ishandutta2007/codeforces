#include <bits/stdc++.h>

using namespace std;

vector<char> h;
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long a=0,b=0,c=0,n=0;
    cin >> s;
    for(int i=4;i<s.size();i++)
    {
        if(s[i]=='y' && s[i-1]=='v' && s[i-2]=='a' && s[i-3]=='e' && s[i-4]=='h')
        {
            h.push_back('(');
            a=a+1;
        }
        if(s[i]=='l' && s[i-1]=='a' && s[i-2]=='t' && s[i-3]=='e' && s[i-4]=='m')
        {
            h.push_back(')');
            b=b+1;
        }
    }
    for(int i=0;i<h.size();i++)
    {
        if(h[i]==')')
        {
            c=c+n;
        }
        if(h[i]=='(')
        {
            n=n+1;
        }
    }
    cout<<c;
    return 0;
}