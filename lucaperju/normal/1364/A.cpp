#include <bits/stdc++.h>

using namespace std;
int v[100005];
int rz[100005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    unsigned long long m,k,t,i,j,p,mxx=0,s,q,nr1=0,nr2=0,nr3=0,n;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(i=1;i<=n;++i)
        {
            cin>>v[i];
            v[i]=v[i]%m;
        }
        s=0;
        for(i=1;i<=n;++i)
            s+=v[i];
        if(s==0)
        {
            cout<<-1<<'\n';
        }
        else
        if(s%m==0)
        {
            for(i=1;i<=n;++i)
                if(v[i]!=0)
                    break;
            for(j=1;j<=n;++j)
                if(v[n-j+1]!=0)
                    break;
            cout<<max(n-i,n-j)<<'\n';
        }
        else
        {
            cout<<n<<'\n';
        }
    }
    return 0;
}