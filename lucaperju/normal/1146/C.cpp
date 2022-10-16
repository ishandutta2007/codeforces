#include <bits/stdc++.h>
/*#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
using namespace std;
const long long INF=100000000000000LL;
int a[105],b[105],v[105],cv[105];
int main()
{
    /*ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);*/
    long long pz,add=1,t,i,j,mn=10000030LL*10000030LL,k=0,mx=-999999999999LL,tot,n,m,obj,cnt=0,cnti=0,b2,a3,b3,ok=0,rz=0,val;
    long long ra,rb,dv=-1,dv1=-1;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int nra=0,nrb=0;
        k=1;
        v[k]=n;
        mx=-1;
        for(pz=1;pz<=9;++pz)
        {
            nra=nrb=0;
            j=1;
            for(i=1;i<=k;++i)
            {
                int cj=j;
                for(;j<=cj+v[i]/2-1;++j)
                    a[++nra]=j;
                for(;j<=cj+v[i]-1;++j)
                    b[++nrb]=j;
            }
            j=0;
            for(i=1;i<=k;++i)
            {
                int ac,bc;
                ac=v[i]/2;
                bc=v[i]-v[i]/2;
                if(ac)
                    cv[++j]=ac;
                if(bc)
                    cv[++j]=bc;
            }
            k=j;
            for(i=1;i<=j;++i)
                v[i]=cv[i];
            if(nra==0 || nrb==0)
                break;
            cout<<nra<<' '<<nrb<<' ';
            for(i=1;i<=nra;++i)
                cout<<a[i]<<' ';
            for(i=1;i<=nrb;++i)
                cout<<b[i]<<' ';
            cin>>val;
            mx=max(mx,val);
            cout<<'\n';
            cout.flush();
        }
        cout<<-1<<' '<<mx<<'\n';
        cout.flush();
    }
    return 0;
}