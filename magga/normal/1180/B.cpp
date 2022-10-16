#include<bits/stdc++.h>
using namespace std;
void solve()
{
    long long int n,ans,max,d;cin>>n;
    max=10000000;
    vector<long long int>v,v1;
    for(long long int i=0;i<n;i++)
    {
        cin>>d;
        if(d<0)
        {
            v.push_back(d);
        }
        else
        {
            d=-d-1;
            v.push_back(d);
        }
        if(d<max)
        {
            max=d;
            ans=i;
        }
    }
    if(n%2==1)
    {
        v[ans]=-v[ans]-1;
    }
    for(long long int i=0;i<n-1;i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<v.back()<<endl;
}
int main()
{
    solve(); 
}