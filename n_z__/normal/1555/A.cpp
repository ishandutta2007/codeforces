#include<bits/stdc++.h>
using namespace std;
#define int long long
main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        if(n<6)cout<<15<<endl;
        else{
            if(n%2==1)n++;
            cout<<n/2*5<<endl;
        }
    }
}