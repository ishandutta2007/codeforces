#include<bits/stdc++.h>
using namespace std;
int a[10000],x[10000];
int main()
{
    int n;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i]>>x[i];
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        if(i!=j)
        {
            if(a[i]+x[i]==a[j]&&a[j]+x[j]==a[i])
            {
                cout<<"YES";
                return 0;
            }
        }
    }
    cout<<"NO";
    return 0;
}