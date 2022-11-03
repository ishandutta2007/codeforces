#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 2e5 + 20;
ll t[maxn] , a[maxn] , res[maxn];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n , k , q;
    cin >> n >> k >> q;
    for(int i = 0; i < n; i++)
    {
        int l , r;
        cin >> l >> r;
        l--;
        t[l]++;
        t[r]--;
    }
    for(int i = 0; i < maxn; i++)
        a[i] = a[i - 1] + t[i];
    for(int i = 0; i < maxn; i++)
        res[i] = res[i - 1] + (a[i] >= k);
    while(q--)
    {
        int a , b;
        cin >> a >> b;
        a--;
        b--;
        cout << res[b] - res[a - 1] << endl;
    }
}