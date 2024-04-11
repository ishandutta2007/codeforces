#include <bits/stdc++.h>
using namespace std;
int v[4],sp[10];
int main()
{
    ios_base::sync_with_stdio(0);
    long long p,add=1,t,h,n,i,j,mn=99999,k=0,mx=-999999999999LL,tot,m,obj,cnt=0,cnti=0,s=0,nri=0,b2,a3,b3,pz=1;
    int i1=-1,j1=-1,i2=-1,j2=-1;
    int f,r,c;
    cin>>v[1]>>v[2]>>v[3];
    sp[1]=1;
    sp[2]=2;
    sp[3]=3;
    sp[4]=1;
    sp[5]=3;
    sp[6]=2;
    sp[7]=1;
    for(i=1;i<=7;++i)
    {
        int cv[4];
        cv[1]=v[1];
        cv[2]=v[2];
        cv[3]=v[3];
        s=0;
        for(j=i;j<=7;++j)
        {
            --cv[sp[j]];
            if(cv[sp[j]]<0)
                break;
            ++s;
        }
        long long cat=max(0,min(min(cv[1]/3-1,cv[2]/2-1),cv[3]/2-1));
        s+=7LL*cat;
        cv[1]-=3LL*cat;
        cv[2]-=2LL*cat;
        cv[3]-=2LL*cat;
        if(j==8)
        {
        j=1;
        while(cv[sp[j]])
        {
            ++s;
            --cv[sp[j]];
            ++j;
            if(j==8)
                j-=7;
        }
        }
        mx=max(mx,s);
    }
    cout<<mx;
    return 0;
}