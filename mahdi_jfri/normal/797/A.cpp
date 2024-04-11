#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e5 + 20;
vector<int> ans;
int main()
{
    ll n , k;
    cin >> n >> k;
    for(int i = 2; i <= n; i++)
    {
        while(n % i == 0)
            n /= i , ans.pb(i);
    }
    if(n > 1)
        ans.pb(n);
    if(ans.size() < k)
    {
        cout << -1;
        return 0;
    }
    ll pro = 1;
    for(auto x : ans)
    {
        if(k > 1)
            cout << x << " " , k--;
        else
            pro *= x;
    }
    cout << pro;
}