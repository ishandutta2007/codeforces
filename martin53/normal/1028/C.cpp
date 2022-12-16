#include<bits/stdc++.h>
using namespace std;
const int nmax=2e5+42;
struct point
{
int x,y;
};
pair<point,point> inp[nmax];
pair<point,point> pref[nmax],suff[nmax];
pair<point,point> merg(pair<point,point> a,pair<point,point> b)
{
    pair<point,point> ret;
    ret.first.x=max(a.first.x,b.first.x);
    ret.first.y=max(a.first.y,b.first.y);

    ret.second.x=min(a.second.x,b.second.x);
    ret.second.y=min(a.second.y,b.second.y);
    return ret;
}
bool ok(pair<point,point> a)
{
    return a.first.x<=a.second.x&&a.first.y<=a.second.y;
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie();
cout.tie();
int n;
cin>>n;
for(int i=1;i<=n;i++)cin>>inp[i].first.x>>inp[i].first.y>>inp[i].second.x>>inp[i].second.y;
pref[1]=inp[1];
for(int i=2;i<=n;i++)
{
    pref[i]=merg(pref[i-1],inp[i]);
}
suff[n]=inp[n];
for(int i=n-1;i>=1;i--)
{
    suff[i]=merg(suff[i+1],inp[i]);
}

if(ok(pref[n-1]))
{
    cout<<pref[n-1].first.x<<" "<<pref[n-1].first.y<<endl;
    return 0;
}
if(ok(suff[2]))
{
    cout<<suff[2].first.x<<" "<<suff[2].first.y<<endl;
    return 0;
}

for(int i=1;i<n;i++)
{
    pair<point,point> now=merg(pref[i],suff[i+2]);
    if(ok(now))
    {
        cout<<now.first.x<<" "<<now.first.y<<endl;
        return 0;
    }
}
return 0;
}