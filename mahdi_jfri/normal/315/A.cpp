#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
const ll maxn = 1e3+1;
ll res;
ll x;
bool y;
int a[maxn],b[maxn],c[maxn];
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i];
        c[b[i]]++;
    }
    for(int i = 0 ; i < n ; i++)
    {
        if (c[a[i]] == 0 || (c[a[i]]==1 && a[i] == b[i]))
            res++;
    }
    cout << res;
}