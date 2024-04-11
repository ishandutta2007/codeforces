#include<bits/stdc++.h>
using namespace std;
long long i,j,k,n,t;
long long m;

int main()
{
    cin>>t;
    for(i=0;i<t;i++)
    {
        long long quicksum=0;
        bool yes=true;
        vector<long long> v;
        cin>>n>>m;
        for(j=0;j<n;j++)
        {
            cin>>k;
            v.push_back(-k);
        }
        sort(v.begin(),v.end());
        for(j=0;j<n;j++)
        {
            quicksum+= (-v[j]);
            if(quicksum/(j+1) < m)
            {
                yes=false;
                break;
            }
        }
        if(yes)
            cout<<n<<"\n";
        else
            cout<<j<<"\n";
    }
}