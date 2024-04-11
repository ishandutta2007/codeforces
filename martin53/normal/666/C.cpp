#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+42,mod=1e9+7,alpha=26;
long long fact[nmax],inv[nmax];
long long my_pow(long long a,long long b)
{
    long long ret=1;
    while(b)
    {
        if(b%2)ret=ret*a%mod;
        a=a*a%mod;
        b=b/2;
    }
    return ret;
}
struct mem
{
int sz;
vector<int> dp;
};
mem all[1000];
int ind=0;
void print(int sz,int n_)
{
    for(int i=1;i<=ind;i++)
        if(all[i].sz==sz)
        {
            cout<<all[i].dp[n_]<<endl;
            return;
        }
}
long long C(int n_,int k_)
{
    return fact[n_]*inv[k_]%mod*inv[n_-k_]%mod;
}
void run(int sz)
{
    for(int i=1;i<=ind;i++)
        if(all[i].sz==sz)return;
    all[++ind].sz=sz;
    long long prod_other=1,prod_f=1,sum=0;
    for(int i=0;i<nmax;i++)
    {
        if(i<sz)all[ind].dp.push_back(0);
        else
        {
        sum=prod_other*C(i-1,sz-1)%mod;
        sum=(1LL*all[ind].dp[i-1]*alpha+sum)%mod;
        all[ind].dp.push_back(sum);
        prod_other=prod_other*(alpha-1)%mod;
        }
    prod_f=prod_f*alpha%mod;
    }
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie();
fact[0]=1;
for(int i=1;i<nmax;i++)
    fact[i]=fact[i-1]*i%mod;
for(int i=0;i<nmax;i++)
    inv[i]=my_pow(fact[i],mod-2);
int q;
int type,val;
cin>>q;
string s;
cin>>s;
run(s.size());
for(int i=1;i<=q;i++)
{
    cin>>type;
    if(type==1)
    {
        cin>>s;
        run(s.size());
    }
    else
    {
        cin>>val;
        print(s.size(),val);
    }
}
return 0;
}