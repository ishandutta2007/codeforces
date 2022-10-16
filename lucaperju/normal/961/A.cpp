#include <iostream>

using namespace std;
int fv[1005];
int main()
{
    int mn=9999999,n,i,a,m;
    cin>>m>>n;
    for(i=1;i<=n;++i)
    {
        cin>>a;
        fv[a]++;
    }
    for(i=1;i<=m;++i)
        if(fv[i]<mn)
            mn=fv[i];
    cout<<mn;
    return 0;
}