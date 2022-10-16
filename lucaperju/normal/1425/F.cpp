#include <bits/stdc++.h>
using namespace std;
int sp[1003];
int rz[1003];
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    long long t,i,j,k,n,q,m;
    cin>>n;
    for(i=n;i>=2;--i)
    {
        cout<<"? "<<1<<' '<<i<<'\n';
        cout.flush();
        int a;
        cin>>a;
        sp[i]=a;
    }
    long long s=0;
    for(i=n;i>=3;--i)
    {
        rz[i]=sp[i]-sp[i-1];
        s+=rz[i];
    }
    cout<<"? "<<2<<' '<<n<<'\n';
    cout.flush();
    int a;
    cin>>a;
    rz[1]=sp[n]-a;
    s+=rz[1];
    rz[2]=sp[n]-s;
    cout<<"! ";
    for(i=1;i<=n;++i)
        cout<<rz[i]<<' ';
    cout<<'\n';
    cout.flush();
    return 0;
}