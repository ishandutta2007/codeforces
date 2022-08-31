#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define mp make_pair
#define pb push_back

using namespace std;
typedef long long ll;
typedef long double ld;

//const int max_n = ;

int main()
{
    int k, a, b;
    cin >> k >> a >> b;
    if (a < b) swap(a, b);
    if (k <= b)
    {
        cout << a / k + b / k;
        return 0;
    }

    if (k > b && k <= a)
    {
        if (a % k != 0)
        {
            cout << -1;
            return 0;
        }
        cout << a / k;
        return 0;
    }
    if (k > a)
    {
        cout << -1;
        return 0;
    }
    return 0;
}