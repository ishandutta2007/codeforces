#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int lgput (long long a, long long exp, long long mod)
{
    long long rez=1;
    while(exp)
        if(exp&1)rez*=a,rez%=mod,--exp;
            else a*=a,a%=mod,exp>>=1;
    rez%=mod;
    return rez;
}
char s[100005],t[1000006];
long long sp[1000006],put[1000006];
long long mod=999999937;
bool verif (int st1, int dr1, int st2, int dr2)
{
    long long val1,val2,s1,s2;
    val1=sp[st1-1];
    val1=(val1*put[dr1-st1+1])%mod;
    s1=sp[dr1]-val1;
    s1+=mod;
    s1%=mod;
    val2=sp[st2-1];
    val2=(val2*put[dr2-st2+1])%mod;
    s2=sp[dr2]-val2;
    s2+=mod;
    s2%=mod;
    if(s1==s2)
        return true;
    return false;
}
int main()
{
    long long n,i,j,m,cnt0=0,cnt1=0,p=1,rezt=0,l0,l1,stcr,drcr,val0,val1,k,a,b,c,d,st0,dr0,st1,dr1;
    cin>>s;
    n=strlen(s);
    cin>>t;
    m=strlen(t);
    for(i=0;i<m;++i)
    {
        put[i]=p;
        p=(p*100LL)%mod;
    }
    for(i=0;i<m;++i)
    {
        sp[i]=(sp[i-1]*100LL)%mod;;
        sp[i]+=t[i]-'a'+2;
        sp[i]+=mod;
        sp[i]%=mod;
    }
    for(i=0;i<n;++i)
    {
        if(s[i]=='0')
            ++cnt0;
        else
            ++cnt1;
    }
    for(int ii=1;ii<=m/cnt0;++ii)
    {
        if(m-cnt0*ii<=0 || (m-cnt0*ii)%cnt1)
            continue;
        l0=ii;
        l1=(m-cnt0*ii)/cnt1;
        stcr=0;
        st0=dr0=st1=dr1=-1;
        k=1;
        for(i=0;i<n;++i)
        {
            if(s[i]=='0')
            {
                drcr=stcr+l0-1;
                if(st0==-1)
                {
                    st0=stcr;
                    dr0=drcr;
                }
                else
                {
                    if(!verif(st0,dr0,stcr,drcr))
                    {
                        k=0;
                        break;
                    }
                }
            }
            else
            {
                drcr=stcr+l1-1;
                if(st1==-1)
                {
                    st1=stcr;
                    dr1=drcr;
                }
                else
                {
                    if(!verif(st1,dr1,stcr,drcr))
                    {
                        k=0;
                        break;
                    }
                }
            }
            stcr=drcr+1;
        }
        if(!verif(st0,dr0,st1,dr1))
            rezt+=k;
    }
    cout<<rezt;
}