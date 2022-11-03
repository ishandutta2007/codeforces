#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e5 + 20;
string s;
char ch;
int main()
{
    cin >> s;
    ch = 'a';
    if(s[0] != ch)
    {
        cout << "NO";
        return 0;
    }
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] <= ch)
            continue;
        else
        {
            ch++;
            if(ch != s[i])
            {cout << "NO";
            return 0;}
        }
    }
    cout << "YES";
}