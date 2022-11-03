#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e5 + 20;
int main()
{
    ll n , m , z;
    cin >> n >> m >> z;
    ll lcm = n * m / __gcd(n , m);
    cout << z / lcm;
}