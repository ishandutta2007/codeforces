//Author:Luogu@N_z_(320087)
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int p=1000000007;
main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int ans=1;
        for(int x=1;x<=2*n;x++)
        if(x!=2)ans*=x,ans%=p;
        cout<<ans<<endl;
    }
}