#include <bits/stdc++.h>
#define pb push_back
#define ll long long

using namespace std;
const int N = 2000;

ll k;
vector<ll> ans;
vector<ll> col;
int main()
{
    cin >> k;
    col.pb(0);
    col.pb(0);
    for (ll i = 2; i <= 100000; i++)
        col.pb(((i-1)*i)/2);
    ll j = col.size()-1;
    ll sum = 0;
    //cout << k << endl;
    if (k == 0)
    {
        cout << 'a';
        return 0;
    }
    while (k != 0)
    {
       // cout << k << ' '<<col[j]<<' '<< ' ' << j << endl;
        ll q = k/col[j];
       // cout << j << endl;
        for (int i = 0; i < q; i++)
            ans.pb(j);
        k -= q*col[j];
        j--;
    }
    for (int i = 0; i < int(ans.size()); i++)
    {
        char c = 'a'+i;
        for (int j = 0; j < ans[i]; j++)
            cout << c;
    }
    return 0;
}