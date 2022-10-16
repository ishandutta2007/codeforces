#include <bits/stdc++.h>

using namespace std;
int v[200005];
int main()
{
    long long i,j,n,m,k=0,cnt=0,s=0,mx=-9999999999LL,mn=9999999999LL,t;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        cnt=0;
        for(i=1;i<=n;++i)
        {
            int a;
            cin>>a;
            v[i]=a%2;
            cnt+=a%2;
        }
        if(k>cnt || (cnt-k)%2==1)
        {
            cout<<"NO\n";
            continue;
        }
        cout<<"YES\n";
        --k;
        for(i=1;k && i<=n;++i)
        {
            if(v[i]==1)
            {
                cout<<i<<' ';
                --k;
            }
        }
        cout<<n<<'\n';
    }
    return 0;
}