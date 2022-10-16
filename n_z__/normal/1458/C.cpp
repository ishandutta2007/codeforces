#include<bits/stdc++.h>
using namespace std;
int a[1001][1001],b[1001][1001],r[3];
main(){
    int T;
    cin>>T;
    while(T--)
    {
        r[0]=r[1]=r[2]=0;
        int n,q;
        cin>>n>>q;
        for(int x=0;x<n;x++)
        for(int y=0;y<n;y++)
        cin>>a[x][y],a[x][y]--;
        pair<int,int>d[3]={{0,0},{1,0},{2,0}};
        for(int x=1;x<=q;x++)
        {
            char c;
            cin>>c;
            d[0].second+=n+(c=='D')-(c=='U');
            d[1].second+=n+(c=='R')-(c=='L');
            if(c=='I')swap(d[1],d[2]);
            if(c=='C')swap(d[0],d[2]);
        }
        for(int x=0;x<n;x++)
        for(int y=0;y<n;y++)
        {
            r[0]=x,r[1]=y,r[2]=a[x][y];
            b[(r[d[0].first]+d[0].second)%n][(r[d[1].first]+d[1].second)%n]=(r[d[2].first]+d[2].second)%n;
        }
        for(int x=0;x<n;x++,cout<<endl)
        for(int y=0;y<n;y++)
        cout<<b[x][y]+1<<' ';
        cout<<endl;
    }
}