#include<bits/stdc++.h>
using namespace std;
int i,j,k,t,n,m;

int main()
{
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n>>m;
        for(j=0;j<n;j++)
        {
            for(k=0;k<m;k++)
            {
                if(j==0 && k==0)
                    cout<<"W";
                else
                    cout<<"B";
            }
            cout<<"\n";
        }
    }
    return 0;
}