#include <bits/stdc++.h>

using namespace std;
int fv[200005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    long long n,i,t,j,k,mx,p,mxx=0,a;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=0;i<n;++i)
            fv[i]=0;
        long long val=2000000000-2000000000%n;
        for(i=1;i<=n;++i)
        {
            int a;
            cin>>a;
            fv[((i-1)+a+val)%n]++;
        }
        for(i=0;i<n;++i)
        {
            if(fv[i]==0)
                break;
        }
        if(i==n)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}