#include<bits/stdc++.h>
using namespace std;
#define int long long
main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int s,n,k;
        cin>>s>>n>>k;
        if(s==k)cout<<"YES"<<endl;
        else if(s<k)cout<<"NO"<<endl;
        else{
            int q;
            if(s/k%2)q=k*(s/k+1)/2;
            else q=(s%k+1)*(s/k/2+1)+(k-s%k-1)*(s/k/2);
            if(q>n)cout<<"NO"<<endl;
            else cout<<"YES"<<endl;
        }
    }
}