#include <bits/stdc++.h>

using namespace std;
long long cmmdc (long long a, long long b)
{
    long long r;
    while(b)
    {r=a%b;a=b;b=r;}
    return a;
}
const long long mod=1000000007;
long long d[100005];
long long cur[105][105],put[105][105],rez[105][105];
int main()
{
    long long i,j=0,n,pz=-1,s=0,x,y,z,a,b,c,m,pr,cnt=0,mx=0,mxx=0,x1,y1,x2,y2,cx=0,cy=0,t;
    cin>>t;
    while(t--)
    {
        cin>>n>>a>>b;
        s=0;
        if(n%2)
        {
            --n;
            s+=a;
        }
        s+=min(n*1LL*a,(n/2)*1LL*b);
        cout<<s<<'\n';
    }
}