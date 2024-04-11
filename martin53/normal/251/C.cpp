#include<bits/stdc++.h>
using namespace std;
int k;
long long brute(long long b,long long a)
{
    long long t=0;
    while(b!=a)
    {
        //cout<<b<<" "<<a<<endl;
        int red=1;
        for(int i=2;i<=k;i++)
            if(b-b%i>=a)
            {
            red=max(red,int(b%i));
            }
            //else cout<<b<<" "<<k<<" "<<b-b%i<<endl;
        b=b-red;
        //cout<<red<<endl;
        t++;
    }
    return t;
}
int main()
{
long long a,b;
cin>>a>>b>>k;
swap(a,b);
//b->a
int g=1;
for(int i=2;i<=k;i++)
{
    g=g*i/__gcd(g,i);
}
if(b-a<=g)cout<<brute(b,a)<<endl;
else
{
    long long b1=b-b%g;
    long long a1=(a+g-1)/g*g;
    cout<<brute(a1,a)+brute(b,b1)+brute(g,0)*((b1-a1)/g)<<endl;
}
return 0;
}