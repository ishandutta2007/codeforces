#include <bits/stdc++.h>
using namespace std;
int cmmdc (int a, int b)
{
    int r;
    while(b)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
int main ()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long n,m,ta,tb,i,j,nrc=0,nrd=0,s=0,t,a,b,c,rz=0,q,pz=-1,k1=0,k2=0,k=0,cnt=0;
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>c;
        long long nra,nrb,nrt;
        nrt=b+c-a;
        nra=b-nrt;
        nrb=c-nrt;
        cout<<min(max(nra,nrb)+1,a-nrt+1)<<'\n';
    }
    return 0;
}