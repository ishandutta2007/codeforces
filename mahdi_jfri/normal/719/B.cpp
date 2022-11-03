#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
string s;
int n;
int res1,res2;
bool x = false;
int r1,b1,r2,b2;
int main()
{
    cin >> n >> s;
    string s1,s2;
    s1 = s2 = s;
    for(int i = 0; i < n; i++)
    {
        if(x)
        {
            s1[i] = 'r';
            s2[i] = 'b';
            x = false;
        }
        else
        {
            s1[i] = 'b';
            s2[i] = 'r';
            x = true;
        }
    }
    for(int i = 0; i < n; i++)
    {
        if(s1[i] != s[i])
        {
            if(s1[i] == 'r')
                r1++;
            else
                b1++;
        }
        if(s2[i] != s[i])
        {
            if(s2[i] == 'r')
                r2++;
            else
                b2++;
        }
    }
    res1 = max(r1,b1);
    res2 = max(r2,b2);
    cout << min(res1,res2);
}