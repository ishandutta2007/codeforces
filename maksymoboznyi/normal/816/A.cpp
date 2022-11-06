#include <bits/stdc++.h>
#define pb push_back
#define ll long long
using namespace std;

char c1, c2, c3, c4;
int a, b;
int main()
{
    cin >> c1 >> c2 >> c3 >> c3 >> c4;
    a = c1-48;
    a*= 10;
    a += c2;
    a -= 48;
    b = c3-48;
    b*= 10;
    b += c4;
    b -= 48;
    //cout << a << ' '<< b << endl;
    int a1, b1,an, ans = 1000000, a2, b2;
    for (int i = 0; i < 24; i++)
    {
        a1 = i;
        if (a1 / 10 == 0)
            b1 = a1*10;
        else
        {
            b1 = a1 % 10*10+a1 / 10;
        }
       // cout << a1 << ' ' << b1 << endl;
        an = a1*60+b1 - a*60-b;
       // cout << an << endl;
        if (an < 0)
            an += 24*60;
        if (an < ans && b1 < 60)
        {
            ans = an;
            a2 = a1;
            b2 = b1;
        }
    }
    cout << ans;
    return 0;
}