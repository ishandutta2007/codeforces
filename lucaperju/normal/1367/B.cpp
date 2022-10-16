#include <bits/stdc++.h>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    unsigned long long t,m,k,i,j,p,mxx=0,s,q,nr1=0,nr2=0,nr3=0,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int cnt0=0,cnt1=0;
        for(i=1;i<=n;++i)
        {
            int a;
            cin>>a;
            a%=2;
            if(a%2==i%2)
            {
                if(a%2==0)
                    ++cnt0;
                else
                    ++cnt1;
            }
        }
        if(cnt0!=cnt1)
        {
            cout<<"-1\n";
        }
        else
            cout<<cnt0<<'\n';
    }
    return 0;
}