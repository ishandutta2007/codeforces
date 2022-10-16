#include <bits/stdc++.h>

using namespace std;
int arb[303];
vector<int> v[303];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long t,i,j,a,b,c,ra,rb,rc,n,d;
    cin>>t;
    while(t--)
    {
        cin>>n>>d;
        int cn=n-1;
        arb[0]=1;
        for(i=1;cn;++i)
        {
            arb[i]=min(arb[i-1]*2,cn);
            cn-=arb[i];
            if(!cn)
                break;
        }
        int niv=i;
        long long sc=0;
        for(i=1;i<=niv;++i)
            sc+=arb[i]*i;
        if(sc>d)
        {
            cout<<"NO\n";
            for(i=0;i<=300;++i)
                arb[i]=0;
            continue;
        }
        while(sc<d && niv!=n-1)
        {
            for(i=niv;i>=1;--i)
            {
                if((arb[i]-1)*2>=(arb[i+1]+1))
                {
                    --arb[i];
                    ++arb[i+1];
                    break;
                }
            }
            if(arb[niv+1])
                ++niv;
            ++sc;
        }
        if(sc!=d)
        {
            cout<<"NO\n";
            for(i=0;i<=300;++i)
                arb[i]=0;
            continue;
        }
        cout<<"YES\n";
    /*    for(i=0;i<=niv;++i)
            cout<<arb[i]<<' ';
        cout<<'\n';*/
        for(i=0;i<=niv;++i)
            v[i].clear();
        v[0].push_back(1);
        int cnt=2;
        for(i=1;i<=niv;++i)
        {
            for(j=1;j<=arb[i];++j)
            {
                cout<<v[i-1][(j+1)/2-1]<<' ';
                v[i].push_back(cnt++);
            }
        }
        for(i=0;i<=300;++i)
            arb[i]=0;
        for(i=0;i<=300;++i)
            v[i].clear();
        cout<<'\n';
    }
    return 0;
}