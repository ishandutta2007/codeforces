#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e5 + 20;
ll res = 1e18;
int main()
{
    int a , b;
    string s;
    cin >> s;
    a = s[1] - '0';
    a += (s[0] - '0') * 10;
    b = s[4] - '0';
    b += (s[3] - '0') * 10;
    for(int i = 0; i < 24; i++)
    {
        int k = i , k1;
        k1 = i % 10;
        k /= 10;
        k1 *= 10;
        k1 += k;
        if(k1 >= 60)
            continue;
        ll x = i * 60 + k1 - a * 60 - b;
        if(x < 0)
            x += 24 * 60;
        res = min(res , x);
    }
    cout << res;
}