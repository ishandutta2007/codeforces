#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e5 + 20;
int _max;
string s;
int solve()
{
    int res = 0;
    for(int i = 0; i < s.size(); i++)
        if(s[i] == 'V' && s[i + 1] == 'K')
            res++;
    return res;
}
int main()
{
    cin >> s;
    _max = solve();
    for(int i = 0; i < s.size(); i++)
    {
        char ch = s[i];
        s[i] = 'V';
        _max = max(_max , solve());
        s[i] = 'K';
        _max = max(_max , solve());
        s[i] = ch;
    }
    cout << _max;
}