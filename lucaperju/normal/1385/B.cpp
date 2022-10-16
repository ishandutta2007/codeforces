#include <bits/stdc++.h>
using namespace std;
int v[55];
int main()
{
    long long n,m,i,j,x,y,k,t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=1;i<=n;++i)
            v[i]=0;
        for(i=1;i<=n*2;++i)
        {
            int a;
            cin>>a;
            if(v[a]==0)
                cout<<a<<' ';
            v[a]=1;
        }
        cout<<'\n';
    }
    return 0;
}