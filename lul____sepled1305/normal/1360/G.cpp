#include<bits/stdc++.h>
using namespace std;
int t;

int main()
{
    cin>>t;
    while(t--)
    {
        int n,m,a,b,i,j;
        cin>>n>>m>>a>>b;
        if(n*a!=m*b)
            cout<<"NO\n";
        else
        {
            cout<<"YES\n";
            for(i=0;i<n;i++)
            {
                int cur = (i*a)%m;
                for(j=0;j<m;j++)
                {
                    if((j-cur+m)%m<a)
                        cout<<"1";
                    else
                        cout<<"0";
                }
                cout<<"\n";
            }
        }
    }
}