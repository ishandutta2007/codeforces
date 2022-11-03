#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a,b;
inline int calc(ll x)
{
    int s=0,t=0; ll p=x;
    while(x) s+=x%10,x/=10,t++;
    if(p==n)
    {
        for(int i=1;i<t;i++) a=a*10+9;
        if(a*10+9==n) {printf("%d",s);exit(0);}
        b=n-a;
    }
    return s;
}
int main()
{
    cin>>n;calc(n);
    cout<<calc(a)+calc(b);
    return 0;
}