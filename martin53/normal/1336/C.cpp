#include <bits/stdc++.h>
using namespace std;
const int nmax=3e3+42,mod=998244353;
string s,t;

int dp[nmax][nmax];

int suff[nmax][nmax];

int n,m;

int st[nmax];

int rec(int le,int ri)
{
    if(le>ri)return 1;

    if(dp[le][ri]!=-1)return dp[le][ri];

    int ret=0,which=ri-le+1;
    //place front
    if(le>m||s[which]==t[le])
        ret=ret+rec(le+1,ri);

    //place back

    //cout<<pos_s<<" "<<to_fill<<" pos_other= "<<pos_other<<endl;

    if(ri>m||s[which]==t[ri])
        ret=ret+rec(le,ri-1);

    ret=ret%mod;

    dp[le][ri]=ret;

    //cout<<le<<" "<<ri<<" -> "<<ret<<endl;

    return ret;
}
int main()
{
    cin>>s>>t;
    n=s.size();
    m=t.size();

    s=" "+s;
    t=" "+t;

    st[0]=1;
    for(int i=1;i<nmax;i++)st[i]=2*st[i-1]%mod;

    memset(dp,-1,sizeof(dp));

    int output=0;
    for(int i=m;i<=n;i++)
        output=(output+rec(1,i))%mod;

    printf("%i\n",output);
    return 0;
}