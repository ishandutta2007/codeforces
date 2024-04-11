#include <bits/stdc++.h>

using namespace std;


const long long mod = 1000000007;

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

vector<long long>v;
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    long long q,h,n,k,s=0,t,i,j,m;
    cin>>t;
    init();
    while(t--)
    {
        q=h=n=k=s=i=j=m=0;
        v.clear();
        cin>>n>>m;
        long long x,y,a,b,p;
        cin>>a>>b>>x>>y>>p;
        long long cnt=0,rz=0;
        long long p1=100-p;
        p=p*1LL*inv[100]%mod;
        p1=p1*1LL*inv[100]%mod;
        cnt=0;
        int da=1,db=1;
        int ai=a,bi=b,dai,dbi,ok=0,ok1=0;
        while(1)
        {
            if(a+da>n || a+da<1)
            {
                da=-da;
            }
            if(b+db>m || b+db<1)
                db=-db;
            ok1=0;
            if(x==a || y==b)
            {
                if(ok==0)
                {
                    rz+=cnt;
                    ok=1;
                    ai=a;
                    bi=b;
                    dai=da;
                    dbi=db;
                    ok1=1;
                }
                else
                {
                    v.push_back(cnt);
                }
                cnt=0;
            }
            if(a==ai && b==bi && da==dai && db==dbi && !ok1 && ok)
                break;
            ++cnt;
            a+=da;
            b+=db;
        }
        n=v.size()-1;
        long long sc=0,pc=1;
        for(i=0;i<=n;++i)
        {
            sc=(sc+pc*1LL*p1%mod*1LL*v[i])%mod;
            pc=pc*1LL*p1%mod;
        }
        /** a = sc + pc * a
        a(1-pc)=sc
        a=sc/(1-pc)
        */
        pc=(1-pc+mod)%mod;
        sc=sc*1LL*lgput(pc,mod-2)%mod;
        rz=(sc+rz)%mod;
        cout<<rz<<'\n';
    }
}