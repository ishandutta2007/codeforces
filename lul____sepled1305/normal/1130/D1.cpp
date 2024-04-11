#include<bits/stdc++.h>
using namespace std;
int a,b,i,j,k,l,o,p,n,m,maxi,longest;
vector<vector<long long> > g;
int main()
{
    cin>>n>>m;
    for(i=0;i<n;i++)
    {
        //cout<<"BUDDD";
        vector<long long> v;
        v.push_back(0);
        //cout<<"GOOOOD";
        g.push_back(v);
        //cout<<"YAAAHHH";
    }
    for(i=0;i<m;i++)
    {
        cin>>a>>b;
        g[a-1].push_back(((b-a)%n+n)%n);
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            p=1e8;
            longest=((j-i)%n+n)%n;
            for(l=1;l<g[j].size();l++)
            {
                if(p>g[j][l])
                    p=g[j][l];
            }
            if(p==1e8) p=0;
            longest+=(n*(g[j].size()-2))+p;
            if(longest>=maxi)
            {
                maxi=longest;
            }
        }
        cout<<maxi<<" ";
        maxi=0;
    }
    return 0;
}