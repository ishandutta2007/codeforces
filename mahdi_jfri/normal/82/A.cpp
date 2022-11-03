#include <bits/stdc++.h>
using namespace std;
#define ll long long
string a[6]={"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"};
int main()
{
    ll b = 1;
    ll n;
    cin >> n;
    ll i = 0;
    while(b*5 < n)
    {
        n-=b*5;
        b*=2;
    }
    cout << a[(n - 1) / b];
}