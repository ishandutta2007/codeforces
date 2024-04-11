#include <bits/stdc++.h>

using namespace std;


/*
const long long mod = 998244353;

long long lgput (long long a, long long exp)
{
    long long rz=1;
    while(exp)
        if(exp&1)
            exp^=1,rz=rz*1LL*a%mod;
        else
            exp>>=1,a=a*1LL*a%mod;
    return rz;
}
long long fct[200005],invfct[200005],inv[200005];
long long put2[200005];
long long cmb (long long n, long long k)
{
    if(n<k || k<0 || n<0)
        return 0;
    return fct[n]*1LL*invfct[k]%mod*1LL*invfct[n-k]%mod;
}
void init ()
{
    inv[1]=fct[0]=fct[1]=invfct[0]=invfct[1]=put2[0]=1,put2[1]=2;
    for(long long i=2;i<=200000;++i)
        put2[i]=put2[i-1]*2LL%mod,inv[i]=(mod-mod/i)*1LL*inv[mod%i]%mod,fct[i]=i*1LL*fct[i-1]%mod,invfct[i]=inv[i]*1LL*invfct[i-1]%mod;
}
*/
char vc[5];
int m3[30][30][30];
int m2[30][30];
int m22[30][30];
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    long long q,i,h,k,j,n,s=0,t;
    cin>>t;
    while(t--)
    {
        int ok=0;
        cin>>n;
        for(i=1;i<=n;++i)
        {
            cin>>vc;
            int nc=strlen(vc);
            if(nc==1)
            {
                ok=1;
                continue;
            }
            else if(nc==2)
            {
                ++m2[vc[0]-'a'][vc[1]-'a'];
                if(m2[vc[1]-'a'][vc[0]-'a'] || m22[vc[1]-'a'][vc[0]-'a'])
                    ok=1;
            }
            else
            {
                int a,b,c;
                a=vc[0]-'a';
                b=vc[1]-'a';
                c=vc[2]-'a';
                ++m3[a][b][c];
                if(m3[c][b][a])
                    ok=1;
                if(m2[c][b])
                    ok=1;
                ++m22[a][b];
            }
        }
        for(int a=0;a<=26;++a)
            for(int b=0;b<=26;++b)
                for(int c=0;c<=26;++c)
                m3[a][b][c]=m2[a][b]=m22[a][b]=0;
        if(ok)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}