#include <bits/stdc++.h>
using namespace std;
long long v[200005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long mxc=0,m,i,j=0,t,x,z,y,n,k;
    long long s=0,mx=0;
    cin>>t;
    while(t--)
    {
        cin>>n;
        long long vlc=3;
        while(1)
        {
            if(n%vlc==0)
            {
                cout<<n/vlc;
                break;
            }
            vlc=(vlc+1LL)*2LL-1LL;
        }
        cout<<'\n';
    }
    return 0;
}