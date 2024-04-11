#include <bits/stdc++.h>
using namespace std;
struct ura
{
    long long a,b;
}v[100003];
bool cmp (ura a, ura b)
{
    return a.b<b.b;
}
int main()
{
    ios_base::sync_with_stdio(false);
    long long t,a,k,x,b,i,n;
    cin>>n;
    for(i=1;i<=n;++i)
        cin>>v[i].a>>v[i].b;
    sort(v+1,v+n+1,cmp);
    int l=1,r=n;
    long long ans=0;
    long long cnt=0;
    while(v[l].a || v[r].a)
    {
        if(v[l].b<=cnt)
        {
            cnt+=v[l].a;
            ans+=v[l].a;
            v[l].a=0;
            ++l;
            continue;
        }
        long long vlc=min(v[r].a,v[l].b-cnt);
        cnt+=vlc;
        v[r].a-=vlc;
        ans+=vlc;
        ans+=vlc;
        if(v[r].a==0)
            --r;
    }
    cout<<ans;
	return 0;
}