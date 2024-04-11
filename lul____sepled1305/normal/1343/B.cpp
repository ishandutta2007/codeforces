#include<bits/stdc++.h>
using namespace std;
int i,j,k,n,m,t;

int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        if(n%4==2)
        {
            cout<<"NO\n";
        }
        else
        {
            cout<<"YES\n";
            for(i=0;i<n/2;i++)
            {
                cout<<2*i+2<<" ";
            }
            for(i=0;i<n/2-1;i++)
            {
                cout<<2*i+1<<" ";
            }
            cout<<2*i+n/2+1<<"\n";
        }
    }
    return 0;
}