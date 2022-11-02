/**The flower for truth is a forget me not. And that flower ...is blue.**/
#include<bits/stdc++.h>
using namespace std;
int T;

int main()
{
        int i,n,j;
        cin>>n;
        int a[n],b[n];
        int ans[n];
        map<int,int> mp;
        for(i=0;i<n;i++)
        {
            ans[i]=0;
            cin>>a[i];
            mp.insert({a[i],i});
        }
        for(i=0;i<n;i++)
        {
            cin>>b[i];
            int place = ((i-mp[b[i]])+n)%n;
            ans[place]++;
        }
        sort(ans,ans+n);
        cout<<ans[n-1]<<"\n";
    return 0;
}