#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define find finddd
const int maxn = 2e5 + 20;
vector<int> leaf , others;
ll last;
int main()
{
    int n , k;
    cin >> n >> k;
    ll tool = (n - 1) / k , x = (n - 1) % k;
    for(int i = 1; i <= k; i++)
        leaf.pb(i);
    for(int i = k + 2; i <= n; i++)
        others.pb(i);
    last = k + 1;
    cout << tool * 2 + min(x , 2LL) << endl;
    for(int i = 0; i < k; i++)
    {
        vector<int> v;
        for(ll j = 0; j < tool - 1; j++)
        {
            v.pb(others.back());
            others.pop_back();
        }
        v.pb(leaf.back());
        leaf.pop_back();
        if(x)
        {
            x--;
            int l = v.back();
            v.pop_back();
            v.pb(others.back());
            others.pop_back();
            v.pb(l);
        }
        cout << last << " " << v[0] << endl;
        for(int i = 1; i < v.size(); i++)
            cout << v[i - 1] << " " << v[i] << endl;
    }
}