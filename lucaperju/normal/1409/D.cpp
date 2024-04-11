#include <bits/stdc++.h>
using namespace std;
int sumc (long long n)
{
    int s=0;
    while(n)
    {
        s+=(n%10LL);
        n/=10LL;
    }
    return s;
}
char v[20];
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t,i,j,k;
    cin>>t;
    while(t--)
    {
        long long n,s;
        cin>>v>>s;
        int l=strlen(v);
        int pz=-1;
        long long vlc=0;
        for(i=0;i<l;++i)
        {
            v[i]-='0';
            vlc=vlc*10LL+v[i];
            if(sumc(vlc+1)<=s)
                pz=i;
        }
        n=vlc;
        if(sumc(n)<=s)
        {
            cout<<0<<'\n';
            continue;
        }
        vlc=0;
        for(i=0;i<=pz;++i)
            vlc=vlc*10LL+v[i];
        ++vlc;
        for(i=pz+1;i<l;++i)
            vlc=vlc*10LL;
        cout<<vlc-n<<'\n';
    }
}