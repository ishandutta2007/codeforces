#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e6 + 20;
ll a[maxn];
string s;
int main()
{
    cin >> s;
    int x = 0;
    while(s[x] == 'a')
        x++;
    if(x == s.size())
    {
        s[s.size() - 1] = 'z';
        cout << s;
        return 0;
    }
    while(x < s.size() && s[x] != 'a')
        s[x]-- , x++;
    cout << s;
}