#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t,i,j,a,b,c,ra,rb,rc;
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>c;
        int mn=100000;
        for(i=1;i<=c*2;++i)
        {
            int sc=max(i-b,b-i);
            int pas=1<<14;
            int kc=i;
            while(pas)
            {
                if(kc+pas*i<=c)
                    kc+=pas*i;
                pas>>=1;
            }
            sc+=min(max(c-kc,kc-c),kc+i-c);
            int cur=100000;
            for(j=1;j*j<=i;++j)
            {
                if(i%j==0)
                {
                    cur=min(cur,max(a-j,j-a));
                    cur=min(cur,max(a-i/j,i/j-a));
                }
            }
            sc+=cur;
            if(sc<mn)
            {
                mn=sc;
                rb=i;
            }
        }
        cout<<mn<<'\n';
        int cur=10000;
        for(i=1;i<=rb;++i)
        {
            if(rb%i==0)
            {
                int dstc=max(a-i,i-a);
                if(dstc<cur)
                {
                    cur=dstc;
                    ra=i;
                }
                dstc=max(a-rb/i,rb/i-a);
                if(dstc<cur)
                {
                    cur=dstc;
                    ra=rb/i;
                }
            }
        }
        cout<<ra<<' '<<rb<<' ';
        int pas=1<<14;
        int kc=rb;
        while(pas)
        {
            if(kc+pas*rb<=c)
                kc+=pas*rb;
            pas>>=1;
        }
        if(c-kc<kc+rb-c)
            cout<<kc<<'\n';
        else
            cout<<kc+rb<<'\n';
    }
    return 0;
}