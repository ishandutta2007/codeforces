#include<bits/stdc++.h>
using namespace std;
long long i,j,k,t,n,a,b,counti;
 int main()
 {
     cin>>t;
     for(i=0;i<t;i++)
     {
        counti=1;
        cin>>n;
        vector<long long> v;
        for(j=0;j<n;j++)
        {
            cin>>a;
            v.push_back(a);
        }
        sort(v.begin(),v.end());
        for(j=1;j<n;j++)
            if(v[j]!=v[j-1]) counti++;
        cout<<counti<<"\n";
     }
 }