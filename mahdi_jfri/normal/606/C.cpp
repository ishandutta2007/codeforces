#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e5 + 20;
const ll inf = 4e18;
ll dp[maxn] , a[maxn] , _max = 1;
set<int> st;
set<int>::iterator it;
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i : a)
    {
        dp[i] = dp[i - 1] + 1;
        _max = max(dp[i] , _max);
    }
    cout << n - _max;
}