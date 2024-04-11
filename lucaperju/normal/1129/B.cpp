#include <bits/stdc++.h>
using namespace std;
long long rez[2005];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long i=0,k,s=0,n,m,d,s1=0,ra,rb,rc,rd,ok,mx=0,a,b;
    char c;
    cin>>k;
    long long val=k%1999;
    if(val!=0)
        val=1999-val;
    long long ck=k+2000LL*val;
    n=2000;
    rez[n]=ck/1999LL;
    rez[n-1]=-val;
    cout<<n<<'\n';
    for(i=1;i<=n;++i)
        cout<<rez[i]<<' ';
    return 0;
}