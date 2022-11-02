#include<bits/stdc++.h>
using namespace std;
int t;

int main()
{
    cin>>t;
    while(t--)
    {
        long long n,ans=0,i,cur;
        cin>>n;
        for(i=1;i<=n/2;i++)
        {
            cur = (2*i+1)*(2*i+1)-(2*i-1)*(2*i-1);
            cur*=i;
            ans+=cur;
        }
        cout<<ans<<"\n";
    }
}