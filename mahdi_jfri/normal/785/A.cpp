#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e5 + 20;
int res;
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        if(s[0] == 'I')
        {
            res += 20;
        }
        else if (s[0] == 'D')
            res += 12;
        else if (s[0] == 'O')
            res += 8;
        else if (s[0] == 'C')
            res += 6;
        else if(s[0] == 'T')
            res += 4;
    }
    cout << res;
}