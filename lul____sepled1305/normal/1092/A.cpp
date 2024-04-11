#include<bits/stdc++.h>
using namespace std;
int n,l,t,i,j,k;
char o;
int main()
{
    cin>>t;
    for(i=1;i<=t;i++)
    {
        cin>>n>>k;
        for(j=1;j<=n;j++)
        {
            o=97+j%k;
            cout<<o;
        }
        cout<<"\n";
    }
    return 0;
}