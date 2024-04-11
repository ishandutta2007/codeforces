#include <bits/stdc++.h>

#define S second
#define F first

using namespace std;
typedef long long ll;



//0:46
/*
0 - 9 : 1989 - 1998
00 - 99 : 1999 - 2098
000 - 999 : 2099 - 3098
0000 - 9999 : 3099 - 13098



*/

pair<ll, ll> m[10];

int main()
{
    ll cur = 1989, pir = 10;
    for (int i = 1; i <= 9; i++)
    {
        m[i] = make_pair(cur, cur + pir - 1);
        cur = cur + pir;
        pir *= 10;
    }

    //for(int i = 1; i <= 9; i++) cout<<m[i].F << ' '<<m[i].S << endl;

    char s[15];
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> s;
        string s1(s);
        int len = s1.length() - 4;
        int a1 = atoi(s + 4);
        ll a = (ll) a1;
        ll pl = 10;
        for (int i = 1; i < len; i++) pl *= 10;
        //cout << pl << endl;
        while (a < m[len].F)
        {
            a += pl;
        }
        cout << a << endl;
    }
}