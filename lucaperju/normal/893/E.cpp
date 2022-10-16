#include <iostream>

using namespace std;
const long long mod=1000000007;
long long cmb[1000050][21];
void frmcmb ()
{
    long long i,j;
    cmb[0][0]=1;
    for(i=1;i<=1000030;++i)
        for(j=0;j<=20;++j)
        {
            if(j==0)
                cmb[i][j]=1;
            else
                cmb[i][j]=(cmb[i-1][j-1]+cmb[i-1][j])%mod;
        }
}
long long lgput (long long cnt , long long put)
{
    long long r=1,p=put;
    if(cnt==0)
        return 1;
    while(cnt!=1)
    {
        if(!(cnt&1))
        {
            p=p*1LL*p%mod;
            cnt>>=1;
        }
        else
        {
            --cnt;
            r=r*1LL*p%mod;
        }
    }
    p=p*1LL*r;
    return p%mod;
}
int main()
{
    long long i,t,x,y,rsp=1,cx,j,cnt;
    cin>>t;
    frmcmb();
    for(i=1;i<=t;++i)
    {
        cin>>x>>y;
        cx=x;
        rsp=1;
        for(j=2;j*j<=cx;++j)
        {
            cnt=0;
            while(cx%j==0)
            {
                cx/=j;
                ++cnt;
            }
            if(cnt)
                rsp=rsp*1LL*cmb[y+cnt-1][cnt]%mod;
        }
        if(cx!=1)
        {
            cnt=1;
            rsp=rsp*1LL*cmb[y+cnt-1][cnt]%mod;
        }
        rsp=rsp%mod;
        rsp=rsp*1LL*lgput(y-1,2)%mod;
        cout<<rsp<<'\n';
    }
    return 0;
}