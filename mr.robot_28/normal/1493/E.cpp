#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define ld long double
#define sz(s) (int)s.size()
string add(string s)
{
    int i = sz(s) - 1;
    while(i >= 0 && s[i] == '1')
    {
        s[i] = '0';
        i--;
    }
    s[i] = '1';
    return s;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    if(a == b)
    {
        cout << a;
        return 0;
    }
    if(a[0] != b[0])
    {
        for(int i = 0; i < n; i++)
        {
            cout << "1";
        }
        return 0;
    }
    if(add(a) == b || b.back() == '1')
    {
        cout << b;
    }
    else{
        cout << add(b);
    }
    return 0;
}