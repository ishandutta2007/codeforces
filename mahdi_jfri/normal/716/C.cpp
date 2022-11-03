#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int n;
    cin >> n;
    n++;
    ll x=2;
    for(long long i=2;i<=n;++i)
    {
        cout << i*(i-1)*(i)-(x/(i-1)) << endl;
        x = i*(i-1);
    }
}