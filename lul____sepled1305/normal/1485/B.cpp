#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,q,k,i;
    cin>>n>>q>>k;
    int a[n+1], pref[n];
    for(i=0;i<n;i++)
        cin>>a[i];
    a[n] = k+1;
    int sum = 0;
    for(i=0;i<n;i++)
    {
        if(i == 0)
            sum = (a[i+1] - 2);
        else
            sum += (a[i+1] - a[i-1] -2);
        pref[i] = sum;
    }
    for(i=0;i<q;i++)
    {
        int l,r;
        cin>>l>>r;
        l--,r--;
        int ans = pref[r];
        if(l > 0)
            ans -= pref[l-1];
        if(l > 0)
            ans += a[l-1];
        if(r < n-1)
            ans += (k - a[r+1] +1);
        cout<<ans<<endl;
    }
    return 0;
}