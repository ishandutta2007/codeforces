#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[100001],c[100001];
main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        int k=n;
        if(k>m)cout<<0<<endl;
        else{
            for(int x=30;x>=0&&m>=k;x--)
            if((m^(1<<x))<m)k|=(1<<x);
            for(int x=0;x<=30&&m>=k;x++)if((k^(1<<x))>k)k|=(1<<x);else if((n^(1<<x))<n)k|=(1<<x);else if((k^(1<<x))<k)k-=(1<<x);
            cout<<(n^k)<<endl;
        }
    }
}