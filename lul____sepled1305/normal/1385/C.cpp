#include<bits/stdc++.h>
using namespace std;
int T;

int main()
{
    cin>>T;
    while(T--)
    {
        int n,i,local_min = 1,last=1;
        cin>>n;
        int a[n+1];
        a[0] = 1e9;
        for(i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        for(i=n-1;i>=1;i--)
        {
            if(a[i]<a[i+1])
            {
                last = i+1;
                break;
            }
        }
        for(i=1;i<last;i++)
        {
            if(a[i]<a[i-1] && a[i]<=a[i+1])
                local_min = i;
        }
        cout<<local_min-1<<"\n";
    }
    return 0;
}