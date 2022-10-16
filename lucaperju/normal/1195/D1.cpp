#include <bits/stdc++.h>

using namespace std;
long long vi[100005];
vector <long long> v[11];
const int mod=998244353;
int sb[25];
int main()
{
    ios_base::sync_with_stdio(0);
    long long t,i,j,cnt=0,k=0,mn=2,n,m,is,js,ib,jb,s=0;
    cin>>n;
    for(i=1;i<=n;++i)
    {
        cin>>vi[i];
        int ca=vi[i];
        cnt=0;
        while(ca)
        {
            ++cnt;
            ca/=10;
        }
        v[cnt].push_back(vi[i]);
    }
    for(int st=1;st<=10;++st)
        for(int dr=1;dr<=10;++dr)
        {
            int cst=st,cdr=dr;
            for(i=1;i<=st+dr;++i)
            {
                if(cdr>cst)
                    sb[i]=2,--cdr;
                else
                    sb[i]=1,--cst;
            }
            for(i=0;i<v[st].size();++i)
            {
                long long a=v[st][i];
                j=st+dr;
                long long p=1;
                while(a)
                {
                    if(sb[j]==1)
                        s=(s+((a%10)*1LL*p)%mod*1LL*v[dr].size())%mod,a/=10;
                    p=(p*10LL)%mod;
                    --j;
                }
            }
            for(i=0;i<v[dr].size();++i)
            {
                long long a=v[dr][i];
                j=st+dr;
                long long p=1;
                while(a)
                {
                    if(sb[j]==2)
                        s=(s+((a%10)*1LL*p)%mod*1LL*v[st].size())%mod,a/=10;
                    p=(p*10LL)%mod;
                    --j;
                }
            }
        }
    cout<<s;
    return 0;
}