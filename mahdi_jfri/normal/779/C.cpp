#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 2e5 + 20;
ll a[maxn] , b[maxn] , res;
set<pair<int , int> > st;
int main()
{
    int n , k;
    cin >> n >> k;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++)
    {
        cin >> b[i];
        st.insert({a[i] - b[i] , i});
    }
    for(auto x : st)
    {
        if(!k)
            res += min(a[x.second] , b[x.second]);
        else
            res += a[x.second] , k--;
    }
    cout << res;
}