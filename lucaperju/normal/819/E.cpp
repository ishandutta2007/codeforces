#include <bits/stdc++.h>

using namespace std;

/*
const long long mod = 998244353;
long long fct[400005],invfct[400005],inv[400005];
long long put2[400005];
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
    for(long long i=2;i<=400000;++i)
        put2[i]=put2[i-1]*2LL%mod,inv[i]=(mod-mod/i)*1LL*inv[mod%i]%mod,fct[i]=i*1LL*fct[i-1]%mod,invfct[i]=inv[i]*1LL*invfct[i-1]%mod;
}
*/
struct ura
{
    int cat,a,b,c,d;
};
ura cycle (int a, int b, int c, int d = 0)
{
    ura x;
    if(d==0)
        x.cat=3;
    else
        x.cat=4;
    x.a=a,x.b=b,x.c=c,x.d=d;
    return x;
}
vector<ura>rz;
void solve23 (int a, int b)
{
    rz.push_back(cycle(1+a,2+b,2+a,3+b));
    rz.push_back(cycle(1+b,1+a,2+b,2+a));
    rz.push_back(cycle(1+b,2+a,3+b,1+a));
}
void solve (int n, int add)
{
    if(n==3)
    {
        rz.push_back(cycle(1+add,2+add,3+add));
        rz.push_back(cycle(1+add,2+add,3+add));
        return;
    }
    if(n==4)
    {
        rz.push_back(cycle(1+add,2+add,4+add,3+add));
        rz.push_back(cycle(1+add,2+add,3+add,4+add));
        rz.push_back(cycle(1+add,3+add,2+add,4+add));
        return;
    }
    if(n==5)
    {
        /**
        3 5 4 2
        3 3 1 5
        4 4 5 2 3
        4 4 3 2 1
        3 4 2 1
        3 3 1 5
        */
        rz.push_back(cycle(5+add,4+add,2+add));
        rz.push_back(cycle(3+add,1+add,5+add));
        rz.push_back(cycle(4+add,5+add,2+add,3+add));
        rz.push_back(cycle(4+add,3+add,2+add,1+add));
        rz.push_back(cycle(4+add,2+add,1+add));
        rz.push_back(cycle(3+add,1+add,5+add));
        return;
    }
    if(n==6)
    {
        solve(4,0+add);
        rz.push_back(cycle(5+add,6+add,4+add));
        rz.push_back(cycle(5+add,6+add,4+add));
        solve23(4+add,0+add);
        return;
    }
    if(n==8)
    {
        solve(4,0+add);
        solve(4,4+add);
        rz.push_back(cycle(1+add,5+add,2+add,6+add));
        rz.push_back(cycle(1+add,5+add,2+add,6+add));
        rz.push_back(cycle(3+add,7+add,4+add,8+add));
        rz.push_back(cycle(3+add,7+add,4+add,8+add));
        rz.push_back(cycle(1+add,7+add,2+add,8+add));
        rz.push_back(cycle(1+add,7+add,2+add,8+add));
        rz.push_back(cycle(3+add,5+add,4+add,6+add));
        rz.push_back(cycle(3+add,5+add,4+add,6+add));
        return;
    }
    if(n%2==1)
    {
        solve(n-3,0+add);
        solve(3,n-3+add);
        for(int i=1;i<=n-3;i+=2)
            solve23(i-1+add,n-3+add);
        return;
    }
    if(n%2==0)
    {
        solve(n-6,0+add);
        solve(6,n-6+add);
        for(int i=1;i<=n-6;i+=2)
        {
            solve23(i-1+add,n-6+add);
            solve23(i-1+add,n-3+add);
        }
        return;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t,i,j,k,m,q,n;
    cin>>n;
    solve(n,0);
    cout<<rz.size()<<'\n';
    for(i=0;i<rz.size();++i)
    {
        cout<<rz[i].cat<<' '<<rz[i].a<<' '<<rz[i].b<<' '<<rz[i].c<<' ';
        if(rz[i].cat==4)
            cout<<rz[i].d<<' ';
        cout<<'\n';
    }
    return 0;
}