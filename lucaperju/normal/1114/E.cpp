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
bool query1 (long long val)
{
    cout<<"> "<<val<<'\n';
    cout.flush();
    long long ok;
    cin>>ok;
    cout.flush();
    return ok;
}
long long query2 (long long val)
{
    cout<<"? "<<val<<'\n';
    cout.flush();
    long long ok;
    cin>>ok;
    cout.flush();
    return ok;
}
int main()
{
    long long i,j=0,n,mn=(1LL<<62)-1+(1LL<<62),k=0,pz=-1,sc=0,x,y,z,a,b,c,m,pas=1LL<<29,pr;
    cin>>n;
    cout.flush();
    srand(time(NULL));
    while(pas)
    {
        if(k+pas<=1000000000LL)
            if(query1(k+pas))
                k+=pas;
        pas>>=1LL;
    }
    if(k==0)
    {
        int val=query1(0);
        if(val==1)
            b=1;
        else
        {
            cout<<"! "<<0<<' '<<0<<'\n';
            cout.flush();
            return 0;
        }
    }
    b=k+1;
    a=0;
    pr=-1;
    for(i=1;i<=28;++i)
    {
        int pz=((rand()%1000+1)*(rand()%1000+1)*(rand()%1000+1))%n+1;
        long long val=query2(pz);
        if(pr!=-1)
            a=cmmdc(a,max(val-pr,pr-val));
        pr=val;
    }
    cout<<"! "<<b-a*1LL*(n-1)<<' '<<a<<'\n';
    cout.flush();
}