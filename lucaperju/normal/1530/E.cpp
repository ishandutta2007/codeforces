#include <bits/stdc++.h>

using namespace std;

/*
const long long mod = 1000000007;
long long fct[200005],invfct[200005],inv[200005];
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
    inv[1]=fct[0]=fct[1]=invfct[0]=invfct[1]=1;
    for(long long i=2;i<=200000;++i)
        inv[i]=(mod-mod/i)*1LL*inv[mod%i]%mod,fct[i]=i*1LL*fct[i-1]%mod,invfct[i]=inv[i]*1LL*invfct[i-1]%mod;
}
*/

int fv[30];
char v[100005];
int getnxt (int a)
{
    for(int i=0;i<=26;++i)
    {
        if(i==a)
            continue;
        if(fv[i]>0)
        {
            --fv[i];
            return i;
        }
    }
    return -1;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    long long n,m,i,j,t,s=0;
    cin>>t;
    while(t--)
    {
        cin>>(v+1);
        for(i=0;i<=26;++i)
            fv[i]=0;
        n=strlen(v+1);
        for(i=1;i<=n;++i)
            ++fv[v[i]-'a'];
        int a=-1,b=-1,c=-1;
        for(i=0;i<=26;++i)
            if(fv[i]==1)
                break;
        if(fv[i]==1)
        {
            cout<<(char)('a'+i);
            --fv[i];
            --n;
            for(i=1;i<=n;++i)
            {
                char c;
                c=getnxt(-1)+'a';
                cout<<c;
            }
            cout<<'\n';
            continue;
        }
        for(i=0;i<=26;++i)
        {
            if(fv[i]>0 && a==-1)
                a=i;
            else if(fv[i]>0 && b==-1)
                b=i;
            else if(fv[i]>0 && c==-1)
                c=i;
        }
        if(fv[a]==n)
        {
            for(i=1;i<=n;++i)
                cout<<(char)('a'+a);
            cout<<'\n';
            continue;
        }
        int pz=a;
        if(fv[a]<=n/2+1){
            cout<<(char)('a'+a);
            --n;
            --fv[a];
            if(fv[pz]==0)
            {
                for(i=1;i<=n;++i)
                {
                    char c;
                    c=getnxt(-1)+'a';
                    cout<<c;
                }
                cout<<'\n';
                continue;
            }
            cout<<(char)('a'+pz);
            --n;
            --fv[pz];
            while(fv[pz]>0)
            {
                char c;
                c=getnxt(pz)+'a';
                cout<<c;
                cout<<(char)('a'+pz);
                --n;
                --n;
                --fv[pz];
            }
            for(i=1;i<=n;++i)
            {
                char c;
                c=getnxt(-1)+'a';
                cout<<c;
            }
            cout<<'\n';
        }
        else
        {
            if(c==-1)
            {
                cout<<(char)('a'+a);
                --fv[a];
                while(fv[b]--)
                    cout<<(char)('a'+b);
                while(fv[a]--)
                    cout<<(char)('a'+a);
                cout<<'\n';
            }
            else
            {
                cout<<(char)('a'+a);
                --fv[a];
                cout<<(char)('a'+b);
                --fv[b];
                while(fv[a]--)
                    cout<<(char)('a'+a);
                cout<<(char)('a'+c);
                --fv[c];
                while(1)
                {
                    int x=getnxt(-1);
                    if(x==-1)
                        break;
                    cout<<(char)('a'+x);
                }
                cout<<'\n';
            }
        }
    }
    return 0;
}