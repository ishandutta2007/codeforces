#include<bits/stdc++.h>
using namespace std;
const int nmax=1e3+42;
set< pair<int,int> > s;
void connect(int x1,int y1,int x2,int y2)
{
    while(x1<x2)
    {
        s.insert({x1,y1});
        x1++;
    }

    while(x1>x2)
    {
        s.insert({x1,y1});
        x1--;
    }

    while(y1<y2)
    {
        s.insert({x1,y1});
        y1++;
    }

    while(y1>y2)
    {
        s.insert({x1,y1});
        y1--;
    }
    s.insert({x1,y1});
}
int main()
{
int xa,ya;
int xb,yb;
int xc,yc;
cin>>xa>>ya>>xb>>yb>>xc>>yc;
int best=1e9,now;
for(int i=0;i<=1000;i++)
    for(int j=0;j<=1000;j++)
    {
        now=abs(xa-i)+abs(ya-j);
        now+=abs(xb-i)+abs(yb-j);
        now+=abs(xc-i)+abs(yc-j);
        if(now<best)
        {
            best=now;
        }
    }

for(int i=0;i<=1000;i++)
    for(int j=0;j<=1000;j++)
    {
        now=abs(xa-i)+abs(ya-j);
        now+=abs(xb-i)+abs(yb-j);
        now+=abs(xc-i)+abs(yc-j);
        if(now==best)
        {
            //cout<<i<<" "<<j<<endl;
            //cout<<best+1<<endl;
            s={};
            connect(i,j,xa,ya);
            connect(i,j,xb,yb);
            connect(i,j,xc,yc);
            if(s.size()!=best+1)continue;
            cout<<best+1<<endl;
            for(auto k:s)
                cout<<k.first<<" "<<k.second<<endl;
            exit(0);
        }
    }
return 0;
}