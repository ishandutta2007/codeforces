
#include <bits/stdc++.h>

using namespace std;
int fv[30];
int main()
{
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        long long k,n,i;
        cin>>n>>k;
        for(i=1;i<=26;++i)
            fv[i]=0;
        for(i=1;i<=n;++i)
        {
            char c;
            cin>>c;
            ++fv[c-'a'+1];
        }
        int nrp=0,nri=0;
        for(i=1;i<=26;++i)
        {
            nrp+=fv[i]/2;
            nri+=fv[i]%2;
        }
        long long mx=2*(nrp/k)+(nrp%k>=(k-nri));
        while(nrp)
        {
            mx=max(mx,2*(nrp/k)+(nrp%k>=(k-nri)));
            --nrp;
            ++nri;
            ++nri;
            mx=max(mx,2*(nrp/k)+(nrp%k>=(k-nri)));
        }
        cout<<mx<<'\n';
    }

    return 0;
}