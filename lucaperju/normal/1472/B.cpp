#include <bits/stdc++.h>
using namespace std;
const long long mod=1000000007;
int v[200003];
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
        v[1]=v[2]=0;
        for(i=1;i<=n;++i)
        {
            int a;
            cin>>a;
            ++v[a];
        }
        if(v[1]%2==1 || v[1]==0 && v[2]%2==1)
            cout<<"No\n";
        else
            cout<<"Yes\n";
    }
    return 0;
}