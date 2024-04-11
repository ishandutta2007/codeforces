#include<bits/stdc++.h>
using namespace std;
int t,n;

int main()
{
    cin>>t;
    while(t--)
    {
        int pow=2;
        cin>>n;
        int ans1=0, ans2=0,sum=0,i,ans;
        for(i=0;i<n;i++)
        {
            sum+=pow;
            pow*=2;
        }
        ans1+=pow/2;
        pow=2;
        for(i=1;i<n/2;i++)
        {
            ans1+=pow;
            pow*=2;
        }
        cout<<2*ans1-sum<<"\n";
    }
    return 0;
}