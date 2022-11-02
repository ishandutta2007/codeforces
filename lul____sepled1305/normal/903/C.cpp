#include<bits/stdc++.h>
using namespace std;
int n,i,j,maxi=0,cur;
int a[6000];

int main()
{
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];
    for(i=0;i<n;i++)
    {
        cur = 0;
        for(j=0;j<n;j++)
        {
            if(a[i]==a[j])
                cur++;
        }
        maxi=max(cur,maxi);
    }
    cout<<maxi;
}