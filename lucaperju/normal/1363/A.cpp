#include <bits/stdc++.h>

using namespace std;
char v[1003];
int st0[1003],dr0[1003],st1[1003],dr1[1003];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long n,k,t,i,j,mx,p,mxx=0,s,q,nr1=0,nr2=0,nr3=0;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        int s=0;
        int cnt0=0;
        for(i=1;i<=n;++i)
        {
            int a;
            cin>>a;
            if(a%2==0)
                ++cnt0;
            s=(s+a)%2;
        }
        if(n==k)
        {
            if(s)
                cout<<"YES\n";
            else
                cout<<"No\n";
        }
        else
        {
            int cnt1=n-cnt0;
            if(cnt0==n)
                cout<<"No\n";
            else
            if(cnt1==n)
            {
                if(k%2==1)
                    cout<<"Yes\n";
                else
                    cout<<"no\n";
            }
            else
                cout<<"YES\n";
        }
    }
    return 0;
}