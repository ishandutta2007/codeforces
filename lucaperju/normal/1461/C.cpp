#include <bits/stdc++.h>

using namespace std;
int v[100003];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long n,j,i,k;
    int t;
    cin>>t;
    while(t--)
    {
        int s=0;
        int m;
        cin>>n>>m;
        for(i=1;i<=n;++i)
            cin>>v[i];
        for(i=n;i>=1;--i)
            if(v[i]!=i)
                break;
        if(i==0)
        {
            cout<<fixed<<setprecision(6)<<1<<'\n';
            for(i=1;i<=m;++i)
            {
                int a;
                double b;
                cin>>a>>b;
            }
            continue;
        }
        double rz=1;
        int pz=i;
        for(i=1;i<=m;++i)
        {
            int a;
            double b;
            cin>>a>>b;
            if(a>=pz)
                rz=rz*(1-b);
        }
        cout<<fixed<<setprecision(6)<<(double)(1-rz)<<'\n';
    }
    return 0;
}