#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const ll maxn = 2e3 + 20;
vector<ll> v[maxn];
ll dp[maxn][maxn];
int main()
{
    int x1 , x2 , y1 , y2 , x , y;
    cin >> x1 >> y1 >> x2 >> y2 >> x >> y;
    if(x2 < x1)
        swap(x2 , x1);
    if(y2 < y1)
        swap(y2 , y1);
    if((x2 - x1) % x || (y2 - y1) % y || (((x2 - x1) / x) % 2) != (((y2 - y1) / y) % 2))
        cout << "NO";
    else
        cout << "YES";
}