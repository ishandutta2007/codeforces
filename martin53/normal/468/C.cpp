#include<bits/stdc++.h>
using namespace std;
int add(long long x)
{
    int s=0;
    while(x)
    {
    s=s+x%10;
    x=x/10;
    }
    return s;
}
long long my_pow(long long a,long long b)
{
    long long p=1;
    for(int i=1;i<=b;i++)p=p*a;
    return p;
}
long long sum(long long x)
{
    //cout<<"sum "<<x<<endl;
    if(x<10)return x*(x+1)/2;
    long long g=x,d=0;
    while(g>=10)
    {
    d++;
    g=g/10;
    }
    long long v=x-g*my_pow(10,d);
    //cout<<"v= "<<v<<endl;

    long long result=sum(v);
    result=result+g*(v+1);
    for(int f=0;f<g;f++)
        result=result+my_pow(10,d)*d*9/2+my_pow(10,d)*f;
    return result;
}
int main()
{
/*
long long q=0;
for(int i=1;i<=1000000;i++)
{
    q=q+add(i);
    if(sum(i)!=q)
    {
    cout<<i<<" "<<sum(i)<<" "<<q<<endl;
    system("pause");
    }

}
return 0;
*/
/*
cout<<sum(2*1e16)<<endl;
cout<<log10(sum(2*1e16))<<endl;
return 0;
*/
long long a;
cin>>a;
long long ok=1,not_ok=2*1e16;

while(not_ok-ok>1)
{
    long long av=(ok+not_ok)/2;
    //cout<<ok<<" "<<not_ok<<" "<<av<<endl;
    if(sum(av)<=a)ok=av;
    else not_ok=av;
}
long long l=1,r=ok;
long long s=sum(r);
//cout<<"s= "<<s<<endl;
//cout<<"r= "<<r<<endl;
while(s!=a)
{
    if(s<a)
    {
        r++;
        s=s+add(r);
    }
    else
    {
        s=s-add(l);
        l++;
    }
}
cout<<l<<" "<<r<<endl;
return 0;
}