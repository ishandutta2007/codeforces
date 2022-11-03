#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
const int maxn =1e6;
string s;
bool t[30];
bool solve(int a)
{
    for(int i = 0 ; i < 26 ; i++)
        t[i] = 0;
    string s1=s;
    stack<int>stck;
    for(int i = a; i < a+26 ; i++)
    {
        if(s[i] != '?')
        {
            if(t[s[i]-'A'] == 1)
                return 0;
            else
                t[s[i]-'A'] =1;
        }
        else
            stck.push(i);
    }
    if(!stck.empty())
    for(int i = 0 ; i < 26 ; i++)
    {
        if(t[i] == 0)
        {
            s1[stck.top()]=i+'A';
            stck.pop();
        }
    }
    s=s1;
    return 1;
}
int main()
{
    cin >> s;
    int n = s.size();
    if(n < 26)
    {
        cout << -1;
        return 0;
    }
    for(int i = 0 ; i <= n-26; i++)
    {
        if(solve(i))
        {
            for(int j = 0; j < n ;j++)
            {
                if(s[j] == '?')
                    s[j]='A';
            }
            cout << s;
            return 0;
        }
    }
    cout << -1;
    return 0;
}