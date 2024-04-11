#include <bits/stdc++.h>
using namespace std;
long long v[200005],n,k;
bool check (long long val)
{
    int cnt1=0,cnt2=0;
    for(int i=1;i<=n;++i)
    {
        int vlc;
        if(v[i]<=val)
            vlc=1;
        else
            vlc=0;
        if(cnt1%2==1 && vlc==1 || cnt1%2==0)
            ++cnt1;
        if(cnt2%2==0 && vlc==1 || cnt2%2==1)
            ++cnt2;
    }
    if(cnt1>=k || cnt2>=k)
        return true;
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int i,j;
    cin>>n>>k;
    for(i=1;i<=n;++i)
        cin>>v[i];
    long long pas=(1LL<<40),rz=0;
    while(pas)
    {
        if(!check(rz+pas))
            rz+=pas;
        pas>>=1LL;
    }
    cout<<rz+1;
    return 0;
}