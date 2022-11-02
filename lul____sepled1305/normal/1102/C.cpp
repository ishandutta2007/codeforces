#include<bits/stdc++.h>
using namespace std;
int n,x,y,k,s;
int a[100005];
int main()
{
    cin>>n>>x>>y;
    if(x>y)
    {
        cout<<n;
    }
    else
    {
        for(k=1;k<=n;k++)
        {
            cin>>a[k];
            if(a[k]<=x)
            {
                s++;
            }
        }
        if(s%2==0) cout<<s/2; else cout<<s/2+1;
    }
    return 0;
}