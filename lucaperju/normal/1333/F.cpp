#include <bits/stdc++.h>

using namespace std;
int v[500005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long i,j,mx=0,n;
    int k;
    cin>>n;
    for(i=1;i<=n;++i)
    {
        for(j=2;j*j<=i;++j)
            if(i%j==0)
                break;
        if(i%j==0)
            v[i]=i/j;
        else
            v[i]=1;
    }
    sort(v+1,v+n+1);
    for(i=2;i<=n;++i)
        cout<<v[i]<<' ';
    return 0;
}