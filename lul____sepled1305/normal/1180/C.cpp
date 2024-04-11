#include<bits/stdc++.h>
using namespace std;
long long n,q,i,j,k,l;
vector<long long> de;
vector<pair<long long, long long> > check;
int main()
{
    cin>>n>>q;
    for(i=1;i<=n;i++)
    {
        scanf("%lld",&l);
        de.push_back(l);
    }
    for(i=0;i<n-1;i++)
    {
        pair<long long, long long> u;
        u.first = de[0];
        u.second = de[1];
        if(de[1]>de[0])
        {
            de.push_back(de[0]);
            de.erase(de.begin());
        }
        else
        {
            de.push_back(de[1]);
            de.erase(de.begin()+1);
        }
        check.push_back(u);
    }
    for(i=0;i<q;i++)
    {
        cin>>k;
        if(k<n)
        {
            cout<<check[k-1].first<<" "<<check[k-1].second<<"\n";
        }
        else
        {
            k=(k-n)%(n-1);
            cout<<de[0]<<" "<<de[k+1]<<"\n";
        }
    }
}