#include <bits/stdc++.h>

using namespace std;
int v[55][55];
int main()
{
    ios_base::sync_with_stdio(false);
    int i,j;
    double n,m;
    cin>>n>>m;
    long long mx=0;
    for(double x=0;x<=n*m;++x)
    {
        double y=(double)m-(double)(x/n);
        int yn=floor(y);
        mx=max(mx,(long long)(x*1LL*(x+1LL)/2LL*(yn+1LL)+yn*1LL*(yn+1LL)/2LL*(x+1LL)));
    }
    cout<<mx;
    return 0;
}