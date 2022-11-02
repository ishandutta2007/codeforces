#include<bits/stdc++.h>
using namespace std;
long long int a,b,c,n,i,j,k,l,sum;
long long int r[500000];
long long int d[500000][2];
vector<pair<long long, long long> > v;
int main()
{
    cin>>n;
    pair<long long, long long> p;
    p.first=0;
        p.second=0;
        v.push_back(p);
    for(i=1;i<=n;i++)
    {
        scanf("%lld",&r[i]);
        a=r[i]^a;
        //cout<<a<<" ";
        pair<long long, long long> o;
        o.first=a;
        o.second=i;
        v.push_back(o);
    }
    sort(v.begin(),v.end());
    long long h=1;
    for(i=0;i<=n;i++)
    {
        if(v[i].first==v[i-1].first)
        {
        }
        else
        {
            h++;
        }
        d[h][v[i].second%2]++;
        //cout<<h<<v[i].first<<v[i].second<<"\n";
        }
    for(i=1;i<=h;i++)
    {
        //cout<<d[2][1];
        sum+=(d[i][0]*d[i][0]-d[i][0])/2;
        sum+=(d[i][1]*d[i][1]-d[i][1])/2;

    }
    cout<<sum;
    return 0;
}