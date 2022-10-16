#include <bits/stdc++.h>
using namespace std;
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    long long t,i,j,k,n,q,rz=0,m;
    cin>>t;
    while(t--)
    {
        long long n;
        long long vlc=1;
        int cnt=0;
        cin>>n;
        while(n>=(vlc*1LL*(vlc+1LL)/2LL))
        {
            n-=(vlc*1LL*(vlc+1LL)/2LL);
            ++cnt;
            vlc=vlc*2LL+1LL;
        }
        cout<<cnt<<'\n';
    }
    return 0;
}