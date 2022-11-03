#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define vi vector<int>
#define find findd
const int maxn = 1e5 + 20;
int a[maxn] , n , k , res;
int main()
{
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    res = a[n - 1];
    int x = n;
    while(2 * k >= x)
        x-- , k--;
    for(int i = 0; i * 2 <= x; i++)
    {
        res = max(a[i] + a[x - i] , res);
    }
    cout << res;
}