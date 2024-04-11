#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
const int maxn = 1e5+20;
int a[4];
bool isp[maxn];
int res;
int main()
{
    ll n , k , w;
    cin >> k >> n >> w;
    int ll a=(w*(w+1)/2)*k - n;
    cout << (a < 0? 0:a);
}