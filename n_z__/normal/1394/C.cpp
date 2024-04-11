#include<bits/stdc++.h>
using namespace std;
#define gety(x) (max(u,b+x)+min(d,a+x))/2
#define cal(x,y) max({x-l,r-x,y-d,u-y,b-y+x,y-x-a})
int main(){
    int n;
    cin>>n;
    int a=1e9,l=1e9,d=1e9,b=-1e9,r=-1e9,u=-1e9;
    for(int x=1;x<=n;x++)
    {
        string s;
        cin>>s;
        int B=0,N=0;
        for(auto q:s)
        if(q=='B')B++;
        else N++;
        l=min(l,B);
        r=max(r,B);
        d=min(d,N);
        u=max(u,N);
        a=min(a,N-B);
        b=max(b,N-B);
    }
    //cout<<l<<','<<r<<','<<d<<','<<u<<','<<a<<','<<b<<endl;
    int mx1=r,mx2=u;
    for(int x=l;x<=r;x++)
    if(cal(x,gety(x))<cal(mx1,mx2))mx1=x,mx2=gety(x);
    cout<<cal(mx1,mx2)<<endl;
    for(int x=1;x<=mx1+mx2;x++)
    cout<<"NB"[x<=mx1];
}