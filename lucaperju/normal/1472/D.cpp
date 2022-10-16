#include <bits/stdc++.h>
using namespace std;
const long long mod=1000000007;
int v[200003];
int dp[200003];
int main()
{
    ios_base::sync_with_stdio(false);
    long long t,n,i,j,k,m;
    long long x1,y1,x2,y2,rz=1;
    cin>>t;
    while(t--)
    {
        long long w,h;
        cin>>n;
        for(i=1;i<=n;++i)
            cin>>v[i];
        sort(v+1,v+n+1);
        long long a=0,b=0;
        for(i=n;i>=1;--i)
        {
            if(i%2==n%2 && v[i]%2==0)
                a+=v[i];
            else if(i%2!=n%2 && v[i]%2==1)
                b+=v[i];
        }
        if(a>b)
            cout<<"Alice\n";
        else if(a==b)
            cout<<"Tie\n";
        else
            cout<<"Bob\n";
    }
    return 0;
}