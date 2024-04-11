#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   int n;cin>>n;int a[n];vector<int> v1,v2;for(int i=0;i<n;++i) {cin>>a[i];if(a[i]%3==0) v1.push_back(i); else v2.push_back(i);}
   bool ok[n]={0};
   if(v1.size()>=n/2)
   {
       cout<<2<<endl;
       for(int i=0;i<n/2;++i) ok[v1[i]]=true;
   }
   else
   {
       cout<<0<<endl;
       for(int i=0;i<n/2;++i)
       {
           ok[v2[i]]=true;
       }
   }
   for(int i=0;i<n;++i) cout<<(ok[i] ? 1 : 0);
    return 0;
}