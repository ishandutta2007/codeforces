#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   int n,d;cin>>n>>d;
   int a[n];for(int i=0;i<n;++i) cin>>a[i];
   sort(a,a+n);reverse(a,a+n);
   int cur=0;int ans=0;
   for(int i=0;i<n;++i)
   {
       cur+=(d+a[i])/a[i];
       if(cur>n) break;
       ++ans;
   }
   cout<<ans;
    return 0;
}