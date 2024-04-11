#include <bits/stdc++.h>
using namespace std;
vector<int>v;
int main ()
{
    ios_base::sync_with_stdio(0);
    int t,m,i,j,k=0,s=0,mn,mx=0;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n>>k;
        v.clear();
        for(i=k+1;i<=n;++i)
            v.push_back(i);
        for(i=k-1;i>=k/2;--i)
        {
            if(i+i+1>k)
                v.push_back(i);
        }
        cout<<v.size()<<'\n';
        for(i=0;i<v.size();++i)
            cout<<v[i]<<' ';
        cout<<'\n';
    }
}