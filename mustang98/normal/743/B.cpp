
#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 100005;

long long pow2[60];

int main()
{
    //ifstream cin("input.txt");
    ll n, k;
    cin >> n >> k;
    pow2[0] = 1;
    for (int i = 1; i < 60; i++) pow2[i] = 2 * pow2[i - 1];
    while(true)
    {
        ll st = 0;
        while(pow2[st] <= k)
        {
            st++;
        }
        st--;
        if (pow2[st] == k)
        {
            cout << st + 1;
            return 0;
        }
        else
        {
            k -= pow2[st];
        }
    }
    return 0;
}