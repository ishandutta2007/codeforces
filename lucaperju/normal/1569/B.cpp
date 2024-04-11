#include <bits/stdc++.h>

using namespace std;

/*
const long long mod = 998244353;
long long fct[200005],invfct[200005],inv[200005];
long long put2[200005];
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
char v[200005];
vector<int>pzs;
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    long long t,i,a,b,j,k,m,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int cnt=0;
        for(i=1;i<=n;++i)
        {
            cin>>v[i];
            if(v[i]=='2')
                ++cnt;
        }
        pzs.clear();
        for(i=1;i<=n;++i)
        {
            if(v[i]=='2')
                pzs.push_back(i);
        }
        if(cnt==0)
        {
            cout<<"YES\n";
            for(i=1;i<=n;++i)
            {
                for(j=1;j<=n;++j)
                {
                    if(i==j)
                        cout<<"X";
                    else
                        cout<<'=';
                }
                cout<<'\n';
            }
            continue;
        }
        if(cnt<=2)
        {
            cout<<"NO\n";
            continue;
        }
        cout<<"YES\n";
        /**
        1->2
        3...n -> 1
        2->3

        */
        for(i=1;i<=n;++i)
        {

            for(j=1;j<=n;++j)
            {
                if(i==j)
                    cout<<"X";
                else
                {
                    if(i==pzs[0] && j==pzs[1] || i!=pzs[0] && i!=pzs[1] && v[i]=='2' && j==pzs[0] || i==pzs[1] && j==pzs[2])
                        cout<<"+";
                    else{
                        swap(i,j);
                        if(i==pzs[0] && j==pzs[1] || i!=pzs[0] && i!=pzs[1] && v[i]=='2' && j==pzs[0] || i==pzs[1] && j==pzs[2])
                            cout<<"-";
                        else cout<<"=";
                        swap(i,j);
                    }
                }
            }
            cout<<'\n';
        }
    }
    return 0;
}