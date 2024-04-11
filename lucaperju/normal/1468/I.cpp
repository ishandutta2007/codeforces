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
int main()
{
    ios_base::sync_with_stdio(false);
    long long t,n,i,j,k,mod,m;
    cin>>n;
    long long x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    long long det=x1*y2-y1*x2;
    det=max(det,-det);
    if(det!=n)
    {
        cout<<"no";
        return 0;
    }
    cout<<"YES\n";
    long long cmdc=cmmdc(max(y1,-y1),max(y2,-y2));
    for(i=0;i<det/cmdc;++i)
        for(j=0;j<cmdc;++j)
            cout<<i<<' '<<j<<'\n';
    return 0;
}