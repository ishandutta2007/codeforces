#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
map<ll,ll> chk;
main()
{
    ios_base::sync_with_stdio(0);
    ll n,tmp,i,j,ans=0;
    cin>>n;
    for (i=0;i<n;i++)
    {
        cin>>tmp;
        for (j = (int)(log2((double)tmp))+1;j<=30;j++) ans+=chk[(ll)(pow(2.0,(double)j))-tmp];
        chk[tmp]++;
    }
    printf("%I64d",ans);
}