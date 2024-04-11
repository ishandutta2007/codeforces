//Author:Luogu@N_z_(320087)
#include<bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    int t;
    cin>>t;
    while(t--){
        int n,m,k;
        cin>>n>>m>>k;
        if(m<n-1)cout<<"NO"<<endl;
        else if(m>n*(n-1)/2)cout<<"NO"<<endl;
        else if(k>=4)cout<<"YES"<<endl;
        else if(k<=1)cout<<"NO"<<endl;
        else if(k==2)if(n==1)cout<<"YES"<<endl;else cout<<"NO"<<endl;
        else if(k==3)if(m==n*(n-1)/2)cout<<"YES"<<endl;else cout<<"NO"<<endl;
    }
}