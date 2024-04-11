#include <bits/stdc++.h>
using namespace std;
long long cmmdc (long long a, long long b)
{
    long long r;
    while(b)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
long long cmmmc(long long a, long long b)
{
    return a*1LL*b/cmmdc(a,b);
}
const long long mod=1000000007;
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    long long n,i,j;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        long long rz=n*2LL;
        long long vlc=1;
        for(i=2;1;++i)
        {
            vlc=cmmmc(vlc,i);
            if(vlc>n)
                break;
            rz=(rz+n/vlc%mod)%mod;
        }
        cout<<rz<<'\n';
    }
    return 0;
}