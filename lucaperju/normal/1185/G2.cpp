#include <bits/stdc++.h>

using namespace std;
const long long mod=1000000007;
long long count1[55][2505];
long long count23[55][55][2505];
long long g[55],t[55];
long long ordine[55][55][55][4];
long long fact[55];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    long long T,n,i,m,j,k,mx,p,mxx=0,s,q,nr1=0,nr2=0,nr3=0;
    cin>>n>>T;
    count1[0][0]=count23[0][0][0]=1;
    for(i=1;i<=n;++i)
    {
        cin>>t[i]>>g[i];
        if(g[i]==1)
        {
            for(long long cat1=i;cat1>=0;--cat1)
                for(long long tc=0;tc+t[i]<=T;++tc)
                    count1[cat1+1][tc+t[i]]=(count1[cat1+1][tc+t[i]]+count1[cat1][tc])%mod;
            ++nr1;
            continue;
        }
        else
            for(long long cat2=i;cat2>=0;--cat2)
                for(long long cat3=i;cat3>=0;--cat3)
                    for(long long tc=0;tc+t[i]<=T;++tc)
                    {
                        if(g[i]==2)
                            count23[cat2+1][cat3][tc+t[i]]=(count23[cat2+1][cat3][tc+t[i]]+count23[cat2][cat3][tc])%mod;
                        else
                            count23[cat2][cat3+1][tc+t[i]]=(count23[cat2][cat3+1][tc+t[i]]+count23[cat2][cat3][tc])%mod;
                    }
        if(g[i]==2)
            ++nr2;
        else
            ++nr3;
    }
    ordine[1][0][0][1]=ordine[0][1][0][2]=ordine[0][0][1][3]=1;
    for(long long cat1=0;cat1<=nr1;++cat1)
        for(long long cat2=0;cat2<=nr2;++cat2)
            for(long long cat3=0;cat3<=nr3;++cat3)
            {
                for(long long lst=1;lst<=3;++lst)
                {
                    if(ordine[cat1][cat2][cat3][lst]==0)
                        continue;
                    for(long long newlst=1;newlst<=3;++newlst)
                    {
                        if(lst==newlst)
                            continue;
                        if(newlst==1)
                            ordine[cat1+1][cat2][cat3][newlst]=(ordine[cat1+1][cat2][cat3][newlst]+ordine[cat1][cat2][cat3][lst])%mod;
                        if(newlst==2)
                            ordine[cat1][cat2+1][cat3][newlst]=(ordine[cat1][cat2+1][cat3][newlst]+ordine[cat1][cat2][cat3][lst])%mod;
                        if(newlst==3)
                            ordine[cat1][cat2][cat3+1][newlst]=(ordine[cat1][cat2][cat3+1][newlst]+ordine[cat1][cat2][cat3][lst])%mod;
                    }
                }
            }
    ordine[0][0][0][1]=1;
    fact[0]=fact[1]=1;
    for(i=2;i<=n;++i)
        fact[i]=(fact[i-1]*1LL*i)%mod;
    long long rz=0;
    long long rzc;
    for(long long cat1=0;cat1<=nr1;++cat1)
        for(long long cat2=0;cat2<=nr2;++cat2)
            for(long long cat3=0;cat3<=nr3;++cat3)
                for(long long tc=0;tc<=T;++tc)
                {
                    rzc=1;
                    rzc=(rzc*1LL*count1[cat1][tc])%mod;
                    rzc=(rzc*1LL*count23[cat2][cat3][T-tc])%mod;
                    if(rzc==0)
                        continue;
                    rzc=(rzc*1LL*fact[cat1])%mod;
                    rzc=(rzc*1LL*fact[cat2])%mod;
                    rzc=(rzc*1LL*fact[cat3])%mod;
                    rzc=(rzc*1LL*((ordine[cat1][cat2][cat3][1]+ordine[cat1][cat2][cat3][2]+ordine[cat1][cat2][cat3][3])%mod))%mod;
                    rz=(rz+rzc)%mod;
                }
    cout<<rz;
    return 0;
}