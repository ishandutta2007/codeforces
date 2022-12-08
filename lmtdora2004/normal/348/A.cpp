#include <bits/stdc++.h>
#define int long long
using namespace std;
 
int ax=0, a[10000000];
signed main()
{
    int n;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
        ax+=a[i];
    }
    sort(a+1, a+n+1);
    cout<<max(a[n], (ax-1)/(n-1)+1);
}