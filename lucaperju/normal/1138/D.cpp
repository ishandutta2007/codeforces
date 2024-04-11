#include <bits/stdc++.h>
using namespace std;
char v[500003],b[500003];
const long long mod=70094273;
int hp[500003],sp0[500003],sp1[500003],sp[500005];
char rz[500003];
int main()
{
    long long n,i,j,m,mn=9999999,pz,s=0,x,y,k=1,mx=0,cnt=0,val=0,st,dr,nr0=0,nr1=0,put=1,idk=0;
    cin>>b;
    n=strlen(b);
    for(i=0;i<n;++i)
        nr0+=(b[i]=='0'),nr1+=(b[i]=='1');
    cin>>v;
    n=strlen(v);
    for(i=0;i<n;++i)
        hp[i]=((hp[i-1]*3LL)%mod+v[i]-'0'+1)%mod;
    for(i=n-1;i>=0;--i)
        sp0[i]=sp0[i+1]+(v[i]=='0'),sp1[i]=sp1[i+1]+(v[i]=='1');
    sp[0]=1;
    for(i=1;i<=n+2;++i)
        sp[i]=(sp[i-1]*3LL)%mod;
    s=hp[n-1];
    if(nr0>=sp0[0] && nr1>=sp1[0])
    {
        nr0-=sp0[0];
        nr1-=sp1[0];
        i=1;
        j=n;
        for(k=0;k<n;++k)
        {
            cout<<v[k];
            rz[++idk]=v[k];
        }
        while(1)
        {
            put=sp[j-i];
            s=(s-(put*1LL*(rz[i]-'0'+1))%mod+mod)%mod;
            ++i;
    //        put/=3;
            if(i>j || hp[j-i]==s)
            {
                if(nr0<sp0[max(j-i+1,0LL)])
                    break;
                if(nr1<sp1[max(j-i+1,0LL)])
                    break;
                for(k=max(j-i+1,0LL);k<n;++k)
                {
                    cout<<v[k];
                    rz[++idk]=v[k];
                    nr0-=(v[k]=='0');
                    nr1-=(v[k]=='1');
                    s=((s*3LL)%mod+v[k]-'0'+1)%mod;
        //            put=(put*3LL)%mod;
                }
                j=i+n-1;
            }
        }
    }
    for(i=1;i<=nr0;++i)
        cout<<0;
    for(i=1;i<=nr1;++i)
        cout<<1;
    return 0;
}