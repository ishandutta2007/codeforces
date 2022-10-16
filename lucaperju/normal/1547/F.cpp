#include <bits/stdc++.h>
using namespace std;
int cmmdc (int a, int b)
{
    int r;
    while(b)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
int v[400005];
int rmq[400005][18];
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int q,m,i,j,l,r,t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=1;i<=n;++i)
            cin>>v[i];
        int gcd=v[1];
        for(i=n+1;i<=n+n;++i)
            v[i]=v[i-n],gcd=cmmdc(gcd,v[i]);
        n+=n;
        for(i=1;i<=n;++i)
            rmq[i][0]=v[i];
        for(int put2=1;put2<=17;++put2)
            for(int i=1;i<=n;++i)
            {
                rmq[i][put2]=cmmdc(rmq[i][put2-1],rmq[max(1,i-(1<<(put2-1)))][put2-1]);
            }
        int mxc=0;
        for(i=n/2;i<=n;++i)
        {
            int pzc=i,sc=v[i];
            int pas=17;
            while(pas>=0)
            {
                if(cmmdc(sc,rmq[pzc][pas])>gcd)
                {
                    sc=cmmdc(sc,rmq[pzc][pas]);
                    pzc-=(1<<pas);
                }
                --pas;
            }
            mxc=max(mxc,i-pzc);
        }
        cout<<mxc<<'\n';
    }
    return 0;
}