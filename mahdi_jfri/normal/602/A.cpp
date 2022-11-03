#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e5 + 20;
int main()
{
    int n , bx;
    cin >> n >> bx;
    ll m = 0 , z = 0 , zarb = 1;
    for(int i = 0; i < n - 1; i++)
        zarb *= bx;
    for(int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        m += zarb * a;
        zarb /= bx;
    }
    cin >> n >> bx;
    zarb = 1;
    for(int i = 0; i < n - 1; i++)
        zarb *= bx;
    for(int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        z += zarb * a;
        zarb /= bx;
    }
    if(m > z)
        cout << '>';
    if(m < z)
        cout << '<';
    if(m == z)
        cout << '=';
}