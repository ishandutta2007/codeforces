#include <bits/stdc++.h>
using namespace std;
struct ura
{
    long long a,b,fel;
};
vector<ura>rz;
int main()
{
    ios_base::sync_with_stdio(false); /// asta mergea oare?
    cin.tie(0);cout.tie(0);
    long long n,i,j=5,s=0;
    cin>>n;
    for(i=n;1;i+=n)
    {
        rz.push_back({n,i,1});
        long long ci=i;
        if((ci&2LL)==0)
            ci=(ci xor (2LL*ci));
        if((((((2*1LL*ci) xor ci)+ci) xor (3*1LL*ci)))==ci-2LL)
            break;
    }
    long long cn=n;
    n=i;
    if((n&2LL)==0)
    {
        rz.push_back({n,n,1});
        rz.push_back({n,2*1LL*n,0});
        n=(n xor (2*1LL*n));
    }
    rz.push_back({n,n,1});
    rz.push_back({n,2*1LL*n,1});
    rz.push_back({2*1LL*n,n,0});
    rz.push_back({((2*1LL*n) xor n),n,1});
    rz.push_back({(((2*1LL*n) xor n)+n),3*1LL*n,0});
    //n=(((((2*1LL*n) xor n)+n) xor (3*1LL*n)));
    //cout<<n<<'\n';
    rz.push_back({n-2LL,n,0});
    for(i=2;i<=999999999999*1LL*3;i*=2LL)
    {
        rz.push_back({i,i,1});
    }
    for(i=2;i<=999999999999*1LL*3;i*=2LL)
    {
        if(n&i)
        {
            rz.push_back({i,n,0});
            n^=i;
        }
    }
    cout<<rz.size()<<'\n';
    for(i=0;i<rz.size();++i)
    {
        if(rz[i].fel==1)
            cout<<rz[i].a<<" + "<<rz[i].b<<'\n';
        else
            cout<<rz[i].a<<" ^ "<<rz[i].b<<'\n';
    }
}