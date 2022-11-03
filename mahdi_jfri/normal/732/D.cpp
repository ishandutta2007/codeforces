#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e8;
const int maxn = 1e5 + 1;
#define pb push_back
int a[maxn];
int b[maxn];
ll sum;
int avvalin[maxn];
int main()
{
    int n , m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 1; i <= m; i++)
        cin >> b[i], sum += b[i] + 1;
    for(int i = 0; i < n; i++)
    {
        if(a[i] != 0 && b[a[i]] <= i && avvalin[a[i]] == 0)
            avvalin[a[i]] = i + 1;
    }
    for(int i = 1; i <= m; i++)
        if(avvalin[i] == 0 || sum > n)
        {
            cout << -1;
            return 0;
        }
    ll x = *max_element(avvalin,avvalin + n);
    if(x <= sum && a[sum - 1] != 0)
        cout << sum;
    else
        cout << x;
}