#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e5 + 20;
string s;
int k , n;
int main()
{
    cin >> n >> k >> s;
    int g = s.find("G") , t = s.find("T");
    if(g > t)
        for(int i = g - k; i > -1; i -= k)
        {
            if(s[i] == '#')
            {
                cout << "NO";
                return 0;
            }
            if(s[i] == 'T')
            {
                cout << "YES";
                return 0;
            }
        }
    else
    for(int i = g + k; i < n; i += k)
    {
        if(s[i] == '#')
        {
            cout << "NO";
            return 0;
        }
        if(s[i] == 'T')
        {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
}