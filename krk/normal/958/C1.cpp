#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1e9+7;
const int N = 1e5+10;

int a[N],pref[N];

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,p;
    cin>>n>>p;
    int ans=-1;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        pref[i]=pref[i-1]+a[i];
        if(pref[i]>=p)pref[i]%=p;
    }

    for(int i=1;i<n;i++){
        int l=pref[i];
        int r=(pref[n]-pref[i]+p)%p;
        ans=max(ans,l+r);
    }
    cout<<ans;
    return 0;
}