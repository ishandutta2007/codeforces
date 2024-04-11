#include<bits/stdc++.h>
using namespace std;
#define int long long
bool isprime(int n)
{
    for(int x=2;x*x<=n;x++)
    if(n%x==0)return false;
    return true;
}
int qp(int x,int n,int p)
{
    int ret=1;
    while(n)
    {
        if(n&1)ret=ret*x%p;
        x=x*x%p,n>>=1;
    }
    return ret;
}
main()
{
    int n;
    cin>>n;
    if(n==4)return puts("YES\n1\n3\n2\n4"),0;
    if(n==1)return puts("YES\n1"),0;
    if(!isprime(n))return puts("NO"),0;
    puts("YES");
    cout<<1<<endl;
    for(int x=2;x<n;x++)
    cout<<x*qp(x-1,n-2,n)%n<<endl;
    cout<<n<<endl;
}