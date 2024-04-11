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
char v[100];
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t,i,n,m,j,k,q;
    cin>>t;
    srand(time(NULL));
    while(t--)
    {
        cin>>n>>k;
        for(i=1;i<=30;++i)
        {
            int a=rand()%(n-1)+2;
            cout<<"? 1 1\n1\n"<<a<<'\n';
            cout.flush();
            cin>>v;
            if(v[0]=='S')
            {
                cout<<"! 1\n";
                cout.flush();
                break;
            }
        }
        if(i<31)
            continue;
        int catc=1;
        int pz;
        while(catc<=n)
        {
            pz=min(n,catc*2);
            cout<<"? "<<pz-catc<<' '<<pz-catc<<'\n';
            for(i=catc+1;i<=pz;++i)
            {
                cout<<i-catc<<' ';
                cout<<'\n';
            }
            for(i=catc+1;i<=pz;++i)
            {
                cout<<i<<' ';
                cout<<'\n';
            }
            cout.flush();
            cin>>v;
            if(v[0]=='F')
                break;
            catc=pz;
        }
        assert(catc<n);
        /// first one is between catc+1 and pz
        int pas=(1<<9);
        while(pas)
        {
            if(catc+pas<=pz)
            {
                cout<<"? "<<pas<<' '<<pas<<'\n';
                for(i=1;i<=pas;++i)
                    cout<<catc+i<<'\n';
                for(i=1;i<=pas;++i)
                    cout<<i<<'\n';
                cout.flush();
                cin>>v;
                if(v[0]=='E')
                    catc+=pas;
            }
            pas>>=1;
        }
        cout<<"! "<<catc+1<<'\n';
        cout.flush();
    }
    return 0;
}