#include<bits/stdc++.h>
using namespace std;
int T;

int main()
{
    cin>>T;
    while(T--)
    {
        int n,i;
        cin>>n;
        int a[n];
        int quick[n+1];
        char c[n];
        for(i=0;i<n;i++)
        {
            cin>>c[i];
            a[i] = c[i]-'0';
        }
        int sum = 0;
        quick[0] = 1;
        for(i=0;i<n;i++)
        {
            sum+=a[i];
            quick[i+1] = sum-i;
        }
        map<int,int> mp;
        for(i=0;i<=n;i++)
        {
            if(mp.count(quick[i]))
                mp[quick[i]]++;
            else
                mp.insert({quick[i],0});
        }
        long long ans = 0;
        for(i=0;i<=n;i++)
        {
            ans+=mp[quick[i]];
        }
        ans/=2;
        cout<<ans<<endl;
    }
    return 0;
}