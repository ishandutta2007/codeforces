#include <bits/stdc++.h>
using namespace std;
const long long MAX=1e9;
long long x1,x2,y11,y2;
long long query(long long a,long long b)
{
    long long x;
    cout<<"? "<<a<<" "<<b<<endl;
    cin>>x;
    /*int lin=0,col=0;
    if(a<x1)
        lin=x1-a;
    else if(a>x2)
        lin=a-x2;
    if(b<y11)
        col=y11-b;
    else if(b>y2)
        col=b-y2;
    x=lin+col;*/
    return x;
}
int main()
{
    //cin>>x1>>y11>>x2>>y2;
    long long x,y;
    x=query(1,1);
    y=query(MAX,1);
    ///prima diagonala e (1,x+1)->(x+1,1)
    ///a doua e (1000000000,y+1)->(1000000000-y,1)
    ///deci i+j=x+2
    ///si i-j=(1000000000-y-1);
    ///deci 2*i=10000000001+x-y;
    ///deci i=(1000000001+x-y)/2
    ///si j=(x+2-i)
    //cout<<x<<" "<<y<<'\n';
    long long i=(MAX+1+x-y+1)/2;
    long long j=x+2-i;
    //cout<<i<<" "<<j<<'\n';
    if(j<1)
        j=1;
    int a=query(i,j);
    long long c1=j+a;
    long long l1=x+2-c1;
    long long l2=c1+(MAX-y-1);
    long long c2=MAX-query(i,MAX);
    /*if(l1==x1&&l2==x2&&c1==y11&&c2==y2)
        cout<<"1\n";
    else
        cout<<"0\n";*/
    cout<<"! "<<l1<<" "<<c1<<" "<<l2<<" "<<c2<<endl;
    return 0;
}