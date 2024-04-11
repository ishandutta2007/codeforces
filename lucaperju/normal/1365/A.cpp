#include <bits/stdc++.h>

using namespace std;
int v[103][103];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long m,n,k,t,i,j,p,mxx=0,s,q,nr1=0,nr2=0,nr3=0;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(i=1;i<=n;++i)
            for(j=1;j<=m;++j)
                cin>>v[i][j];
        int nf=n,mf=m;
        for(i=1;i<=n;++i)
        {
            int cnt=0;
            for(j=1;j<=m;++j)
                if(v[i][j])
                    cnt=1;
            if(cnt)
                --nf;
        }
        for(j=1;j<=m;++j)
        {
            int cnt=0;
            for(i=1;i<=n;++i)
                if(v[i][j])
                    cnt=1;
            if(cnt)
                --mf;
        }
        nf=min(nf,mf);
        if(nf%2==0)
        {
            cout<<"Vivek\n";
        }
        else
            cout<<"Ashish\n";
    }
    return 0;
}