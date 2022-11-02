#include<bits/stdc++.h>
using namespace std;
long long a,n,i,j,k,o,sum,pos1=1,pos2=1;
vector<pair<long long,long long>> v;
int main()
{
    cin>>n;
    for(i=1;i<=2*n;i++)
    {
        cin>>j;
        pair<long long,long long> p;
        p.first=j;
        p.second=i;
        v.push_back(p);
    }
    sort(v.begin(),v.end());
    for(i=0;i<n;i++)
    {
        if(abs(v[2*i+1].second-pos1)+abs(v[2*i].second-pos2)<=abs(v[2*i+1].second-pos2)+abs(v[2*i].second-pos1))
        {
            sum+=abs(v[2*i+1].second-pos1)+abs(v[2*i].second-pos2);
            pos1=v[2*i+1].second;
            pos2=v[2*i].second;
        }
        else
        {
            sum+=abs(v[2*i+1].second-pos2)+abs(v[2*i].second-pos1);
            pos2=v[2*i+1].second;
            pos1=v[2*i].second;
        }
        //cout<<sum<<"\n";
    }
    cout<<sum;
    //cout<<v[1].second;
    return 0;
}