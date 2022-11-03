#include<bits/stdc++.h>
using namespace std;
int t;

int main()
{
    cin>>t;
    while(t--)
    {
        int n,k,sum=0,i,runner=0;
        cin>>n>>k;
        int a[n],b[n];
        for(i=0;i<n;i++)
        {
            cin>>a[i];
            sum+=a[i];
        }
        for(i=0;i<n;i++)
            cin>>b[i];
        sort(a,a+n); sort(b,b+n);
        while(k--)
        {
            if(a[runner]>b[n-1-runner])
                break;
            else
            {
                sum+=b[n-1-runner]-a[runner];
                runner++;
            }
        }
        cout<<sum<<"\n";
    }
}