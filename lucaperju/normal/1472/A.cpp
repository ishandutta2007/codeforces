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
        cin>>w>>h>>n;
        long long cnt=1;
        while(cnt<n)
        {
            if(w%2==0)
            {
                w/=2;
                cnt*=2;
            }
            else if(h%2==0)
            {
                h/=2;
                cnt*=2;
            }
            else
                break;
        }
        if(cnt<n)
            cout<<"No\n";
        else
            cout<<"Yes\n";
    }
    return 0;
}