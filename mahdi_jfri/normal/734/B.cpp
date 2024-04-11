#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e5 + 20;
int a , b , c , d , sum;
int main()
{
    cin >> a >> b >> c >> d;
    while(a && c && d)
    {
        sum += 256;
        a--;
        c--;
        d--;
    }
    while(a && b)
    {
        sum += 32;
        a--;
        b--;
    }
    cout << sum;
}