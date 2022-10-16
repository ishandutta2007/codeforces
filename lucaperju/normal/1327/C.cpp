#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t,i,j,n,m;
    cin>>n>>m;
    cout<<n-1+m-1+n*m-1<<'\n';
    for(i=1;i<n;++i)
        cout<<"U";
    for(i=1;i<m;++i)
        cout<<"L";
    for(i=1;i<=n;++i)
    {
        if(i%2)
        {
            for(j=1;j<m;++j)
                cout<<'R';
            if(i!=n)
            cout<<'D';
        }
        else
        {
            for(j=1;j<m;++j)
                cout<<'L';
            if(i!=n)
            cout<<'D';
        }
    }
    return 0;
}