#include<bits/stdc++.h>
using namespace std;
long long t,n,i,j,k,mid,print;
 
int main()
{
    cin>>t;
    for(i=0;i<t;i++)
    {
        vector<long long> v;
        cin>>n;
        for(j=0;j<n;j++)
        {
            cin>>k;
            v.push_back(k);
        }
        sort(v.begin(),v.end());
        mid=(v.size()-1)/2;
        cout<<v[mid]<<" ";
        for(j=1;j<n;j++)
        {
            if(j%2==1)
            {
                cout<<v[mid+(j+1)/2]<<" ";
            }
            else
            {
                cout<<v[mid-(j+1)/2]<<" ";
            }
        }
        cout<<"\n";
    }
}