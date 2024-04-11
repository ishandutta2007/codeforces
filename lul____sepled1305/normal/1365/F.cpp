#include<bits/stdc++.h>
using namespace std;
int T;

int main()
{
    cin>>T;
    while(T--)
    {
        int n,i,j;
        cin>>n;
        bool pass=true;
        int a[n],b[n];
        pair<int,int> pa[n],pb[n];
        for(i=0;i<n;i++)
            cin>>a[i];
        for(i=0;i<n;i++)
            cin>>b[i];
        for(i=0;i<n;i++)
        {
            if(n%2==1 && i==n/2)
            {
                continue;
            }
            else
            {
                pa[i]={a[i],a[n-1-i]};
                pb[i]={b[i],b[n-1-i]};
            }
        }
        if(n%2==1)
        {
            if(a[n/2]!=b[n/2])
                pass = false;
            pa[n/2] = {a[n/2],a[n/2]};
            pb[n/2] = {b[n/2],b[n/2]};
        }
        sort(pa,pa+n);
        sort(pb,pb+n);
        for(i=0;i<n;i++)
            if(pa[i]!=pb[i])
                pass = false;
        if(pass)
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
}