#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza

using namespace std;
typedef long long ll;

const int max_n = 200008;

int main()
{
    ll n = 0, a = 0, b = 0, c = 0;
    cin >> n >> a >> b >> c;
    ll ost = n % 4;
    if (ost == 0)
    {
        cout << 0;
    }
    else if(ost == 3)
    {
        cout << min(a, min(b + c, c + c + c));
    }
    else if (ost == 2)
    {
        cout << min(a + a, min(b, c + c));
    }
    else
    {
        cout << min(a + a + a, min(b + a, c));
    }
    return 0;
}