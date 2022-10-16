#include <bits/stdc++.h>
using namespace std;
char v[1003];
int n;
map<int,int>mp[1050000];
int isok[1050000],k;
int dfs (int pz, long long mask)
{
    if(!isok[mask])
        return -1000;
    if(pz==n+1)
        return 0;
    if(mp[mask][pz]>0)
        return mp[mask][pz]-1;
    if(v[pz]-'0'!=k && k%(v[pz]-'0')==0)
    {
        int x;
        x=dfs(pz+1,0)+1;
        mp[mask][pz]=x+1;
        return x;
    }
    int vlc=max(dfs(pz+1,mask),dfs(pz+1,(((mask<<(v[pz]-'0'))&((1<<k)-1))|(1<<(v[pz]-'0'-1)))&((1<<k)-1))+1);
    mp[mask][pz]=vlc+1;
    return vlc;
}
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>(v+1);
    n=strlen(v+1);
    cin>>k;
    for(int mask=0;mask<(1<<(k-1));++mask)
        isok[mask]=1;
    for(int i=1;i<k;++i)
        if(k%i==0)
            for(long long mask=(1<<(k-1));mask<(1<<k);++mask)
                if((mask&(1<<(i-1))) || (mask&(mask<<i)))
                    isok[mask]=1;
    int rz=n-dfs(1,0);
    cout<<rz;
}