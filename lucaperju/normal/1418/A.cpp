#include <bits/stdc++.h>
using namespace std;
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    long long t,i,j,k;
    cin>>t;
    while(t--)
    {
        long long x,y;
        cin>>x>>y>>k;
        long long need=(y+1)*1LL*k;
        --need;
        --x;
        cout<<(need-1LL)/x+1LL+k<<'\n';
    }
    return 0;
}