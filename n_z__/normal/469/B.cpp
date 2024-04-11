#include<bits/stdc++.h>
using namespace std;
int a[51][2];
bool b[10001];
int main()
{
    int p,q,l,r;
    cin>>p>>q>>l>>r;
    for(int x=1;x<=p;x++)
    {
        int y,z;
        cin>>y>>z;
        for(int o=y;o<=z;o++)
        b[o]=true;
    }
    for(int x=1;x<=q;x++)
    cin>>a[x][0]>>a[x][1];
    int ans=0;
    for(int x=l;x<=r;x++)
    {
        for(int y=1;y<=q;y++)
        for(int z=a[y][0]+x;z<=a[y][1]+x;z++)
        if(b[z]==true){ans++;goto nxt;}
        nxt:;
    }
    cout<<ans<<endl;
}