#include <bits/stdc++.h>

using namespace std;
int v[200005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long t,m,k,i,j,p,mxx=0,s,q,nr1=0,nr2=0,nr3=0,n;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        for(i=1;i<=n;++i)
        {
            char c;
            cin>>c;
            v[i]=c-'0';
        }
        for(i=1;i<=n;++i)
            if(v[i]==1)
                break;
        if(i==n+1)
        {
            cout<<(n-1)/(k+1)+1<<'\n';
            continue;
        }
        int rz=0;
        int ci=i;
        i-=(k+1);
        if(i>0)
            rz+=(i-1)/(k+1)+1;
        int cnt=0;
        for(i=ci+1;i<=n;++i)
        {
            if(v[i]==0)
                ++cnt;
            else
            {
                cnt-=2*k;
                if(cnt>0)
                    rz+=(cnt-1)/(k+1)+1;
                cnt=0;
            }
        }
        cnt-=k;
        if(cnt>0)
            rz+=(cnt-1)/(k+1)+1;
        cout<<rz<<'\n';
    }
    return 0;
}