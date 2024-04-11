#include <bits/stdc++.h>
using namespace std;
struct ura
{
    int x,y;
}v[800003];
bool cmp (ura a, ura b)
{
    return a.x+a.y<b.x+b.y;
}
int main()
{
    int n,i,j;
    long long minval=0;
    cin>>n;
    for(i=1;i<=n;++i)
        cin>>v[i].x>>v[i].y;
    sort(v+1,v+n+1,cmp);
    multiset<int>l,r;
    l.insert(0);
    r.insert(0);
    int offsetr=0;
    for(i=1;i<=n;++i)
    {
        offsetr=v[i].x+v[i].y;
        int xc=v[i].x;
        if(xc<=*prev(l.end()))
        {
            minval+=*prev(l.end())-xc;
            l.insert(xc);
            l.insert(xc);
            r.insert(*prev(l.end())-offsetr);
            l.erase(prev(l.end()));
        }
        else if(xc>=*r.begin()+offsetr)
        {
            minval+=xc-(*r.begin()+offsetr);
            r.insert(xc-offsetr);
            r.insert(xc-offsetr);
            l.insert(*r.begin()+offsetr);
            r.erase(r.begin());
        }
        else
        {
            l.insert(xc);
            r.insert(xc-offsetr);
        }
    }
    cout<<minval;
    return 0;
}