#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e5 + 20;
int a[maxn] , res = 1e9;
int main()
{
    int n , m , k;
    cin >> n >> m >> k;
    m--;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < n; i++)
    {
        if(a[i] == 0 || a[i] > k)
            continue;
        if(i < m)
            res = min(res , 10 * (m - i));
        else
            res = min(res , 10 * (i - m));
    }
    cout << res;
}