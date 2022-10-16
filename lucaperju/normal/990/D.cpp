#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
int v[1003][1003];
int main()
{
    int n,a,b,cat,i,j;
    cin>>n>>a>>b;
    if(n==2 && a==1 && b==1 || n==3 && a==1 && b==1 || b!=1 && a!=1)
    {
        cout<<"NO";
        return 0;
    }
    cout<<"YES\n";
    if(n==1)
    {
        cout<<0;
        return 0;
    }
    cat=max(a,b)-1;
    for(i=1;i<n-cat;++i)
        v[i][i+1]=v[i+1][i]=1;
    for(i=1;i<=n;++i)
    {
        for(j=1;j<=n;++j)
        {
            if(a<b && i!=j)
                cout<<1-v[i][j];
            else
                cout<<v[i][j];
        }
        cout<<'\n';
    }
}