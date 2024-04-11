#include<bits/stdc++.h>
using namespace std;
long long a,b,c,i,j,n,k,m;
long long bb[200005];
pair<long long, long long> minu[200005];

int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>bb[i];
        minu[i].first=i-bb[i];
        minu[i].second = bb[i];
    }
    sort(minu+1,minu+n+1);
    long long now,maxi=0;
    now=minu[1].first;
    for(i=1;i<=n;i++)
    {
        if(now==minu[i].first)
        {
            k+=minu[i].second;
        } else
        {
            if(k>maxi)
            {
                maxi=k;
                //cout<<minu[i-1].first;
            }
            k=0;
            now=minu[i].first;
            k+=minu[i].second;
        }
    }
    if(k>maxi)
    {
        maxi=k;
    }
    cout<<maxi;
    //cout<<minu[1].first;
}