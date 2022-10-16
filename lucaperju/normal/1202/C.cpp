#include <bits/stdc++.h>

using namespace std;
char a[200005];
int main()
{
    ios_base::sync_with_stdio(0);
    long long k,t,i,j=0,cnt=1,n,m,is,js,ib,jb,s=0,mx=0,cur=0,q;
    cin>>t;
    while(t--)
    {
        int xmx=0,xmn=0,ymx=0,ymn=0;
        cin>>a;
        n=strlen(a);
        int x=0,y=0;
        int cntxmx=0,cntxmn=0,cntymx=0,cntymn=0;
        for(i=0;i<n;++i)
        {
            if(a[i]=='W')
                ++x;
            if(a[i]=='S')
                --x;
            if(a[i]=='A')
                --y;
            if(a[i]=='D')
                ++y;
            if(x>xmx)
                xmx=x;
            if(x<xmn)
                xmn=x;
            if(y>ymx)
                ymx=y;
            if(y<ymn)
                ymn=y;
        }
        x=0;
        y=0;
        int ok1=1,ok2=1;
        int okxmx=0,okxmn=0,okymx=0,okymn=0;
        if(x==xmx)
            {
                if(okxmx==0)
                    ++okxmx;
                if(okxmn==1)
                    ++okxmn;
                if(okxmx==2)
                    ++okxmx;
            }
            if(x==xmn)
            {
                if(okxmn==0)
                    ++okxmn;
                if(okxmx==1)
                    ++okxmx;
                if(okxmn==2)
                    ++okxmn;
            }
            if(y==ymx)
            {
                if(okymx==0)
                    ++okymx;
                if(okymn==1)
                    ++okymn;
                if(okymx==2)
                    ++okymx;
            }
            if(y==ymn)
            {
                if(okymn==0)
                    ++okymn;
                if(okymx==1)
                    ++okymx;
                if(okymn==2)
                    ++okymn;
            }
        for(i=0;i<n;++i)
        {
            if(a[i]=='W')
                ++x;
            if(a[i]=='S')
                --x;
            if(a[i]=='A')
                --y;
            if(a[i]=='D')
                ++y;
            if(x==xmx)
            {
                if(okxmx==0)
                    ++okxmx;
                if(okxmn==1)
                    ++okxmn;
                if(okxmx==2)
                    ++okxmx;
            }
            if(x==xmn)
            {
                if(okxmn==0)
                    ++okxmn;
                if(okxmx==1)
                    ++okxmx;
                if(okxmn==2)
                    ++okxmn;
            }
            if(y==ymx)
            {
                if(okymx==0)
                    ++okymx;
                if(okymn==1)
                    ++okymn;
                if(okymx==2)
                    ++okymx;
            }
            if(y==ymn)
            {
                if(okymn==0)
                    ++okymn;
                if(okymx==1)
                    ++okymx;
                if(okymn==2)
                    ++okymn;
            }
        }
        if(okxmx==3 || okxmn==3)
            ok1=0;
        if(okymx==3 || okymn==3)
            ok2=0;
        long long d1=xmx-xmn+1;
        long long d2=ymx-ymn+1;
        if(d2<d1)
            swap(d1,d2),swap(ok1,ok2);
        if(d1>2 && ok1)
            cout<<(d1-1)*1LL*d2<<'\n';
        else if (d2>2 && ok2)
            cout<<d1*1LL*(d2-1)<<'\n';
        else
            cout<<d1*1LL*d2<<'\n';
    }
    return 0;
}