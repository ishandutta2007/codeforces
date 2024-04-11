#include<bits/stdc++.h>
using namespace std;
long long sum;
int t,j,i,n;

int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        int maxi=-1e9-1;
        bool pos;
        sum=0;
        cin>>j;
        if(j>0)
        {
            pos = true;
        }
        else
        {
            pos=false;
        }
        maxi=j;
        for(i=1;i<n;i++)
        {
            cin>>j;
            if(pos && j<0)
            {
                sum+=maxi;
                maxi=j;
                pos = false;
            }
            else if(!pos && j>0)
            {
                sum+=maxi;
                maxi=j;
                pos=true;
            }

            if(j>maxi)
                maxi=j;
        }
        sum+=maxi;
        cout<<sum<<"\n";

    }
    return 0;
}