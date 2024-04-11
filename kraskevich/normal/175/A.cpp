#include <iostream>
using namespace std;

#define ll long long

ll val(string s, int l, int r)
{
    if(r - l > 8)
         return 1000 * 1000 + 1;
    ll cur = 0, t = 1;
    for(int i = r; i >= l; --i)
    {
            cur += t * (s[i] - '0');
            t *= 10;
    }
    return cur;
}

bool ok(string s, int l, int r)
{
     if(r != l && s[l] == '0')
               return false;
     return val(s, l, r) <= 1000 * 1000;
}

int main()
{
    ios_base::sync_with_stdio(0);
    
    string s;
    
    cin >> s;
    
    ll res = -1;
    
    for(int i = 1; i < s.length(); ++i)
            for(int j = i + 1; j < s.length(); ++j)
                    {
                            ll cur1 = val(s, 0, i - 1);
                            ll cur2 = val(s, i, j - 1);
                            ll cur3 = val(s, j, s.length() - 1);
                            if(ok(s, 0, i - 1) && ok(s, i, j - 1) && ok(s, j, s.length() - 1))
                                    res = max(res, cur1 + cur2 + cur3);
                    }
    
    cout << res;
    
    cin >> s; 
    
    return 0;
}