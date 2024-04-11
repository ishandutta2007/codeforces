#include<bits/stdc++.h>
using namespace std;
int a,b,c,i,n,j,k,mini=1e9,sum,h;
int r[200000];
int check(int s)
{
    int maci=1e9,l=1;
    while(l<=s)
    {
        if(s%l==0)
        {
            if(s/l+l*r[0]<maci)
            {
                maci=s/l+l*r[0];
            }
        }
        l++;
    }
    return r[0]+s-maci;
}
int main()
{
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>r[i];
        sum+=r[i];
    }
    sort(r,r+n);
    for(i=1;i<n;i++)
    {
        h=check(r[i]);
        if(sum-h<mini)
        {
            mini=sum-h;
        }
    }
    if(n!=1)
    cout<<mini;
    else
        cout<<r[0];
    return 0;
}