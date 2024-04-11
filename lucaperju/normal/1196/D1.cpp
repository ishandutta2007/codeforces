#include <bits/stdc++.h>

using namespace std;
int spr[200005],spg[200005],spb[200005];
int main()
{
    int i,j,n,m,k=0,cnt=0,s=0,mx=-9999999999LL,mn=9999999999LL,t;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        for(i=1;i<=n;++i)
        {
            char c;
            cin>>c;
            int pz=(i-1)%3+1;
            if(c=='R')
            {
                if(pz==1)
                    ++spg[i],++spb[i];
                else
                if(pz==2)
                    ++spr[i],++spg[i];
                else
                if(pz==3)
                    ++spb[i],++spr[i];
            }
            else
            if(c=='G')
            {
                if(pz==2)
                    ++spg[i],++spb[i];
                else
                if(pz==3)
                    ++spr[i],++spg[i];
                else
                if(pz==1)
                    ++spb[i],++spr[i];
            }
            else
            if(c=='B')
            {
                if(pz==3)
                    ++spg[i],++spb[i];
                else
                if(pz==1)
                    ++spr[i],++spg[i];
                else
                if(pz==2)
                    ++spb[i],++spr[i];
            }
            spr[i]+=spr[i-1];
            spg[i]+=spg[i-1];
            spb[i]+=spb[i-1];
        }
        mn=300000;
        for(i=k;i<=n;++i)
        {
            mn=min(mn,spr[i]-spr[i-k]);
            mn=min(mn,spb[i]-spb[i-k]);
            mn=min(mn,spg[i]-spg[i-k]);
        }
        for(i=1;i<=n;++i)
            spr[i]=spg[i]=spb[i]=0;
        cout<<mn<<'\n';
    }
    return 0;
}