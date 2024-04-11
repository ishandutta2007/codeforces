#include<bits/stdc++.h>
using namespace std;
int b[501][501],vx[21],vy[21];
int n,d;
int f(int x,int y){
    if(x*x+y*y>=d*d)return 1;
    if(b[x+250][y+250]>=0)return b[x+250][y+250];
    for(int z=1;z<=n;z++)if(!f(x+vx[z],y+vy[z]))return (b[x+250][y+250]=1);
    return (b[x+250][y+250]=0);
}
int main(){
    int cx,cy;
    cin>>cx>>cy>>n>>d;
    for(int x=1;x<=n;x++)cin>>vx[x]>>vy[x];
    memset(b,-1,sizeof(b));
    cout<<(f(cx,cy)?"Anton":"Dasha")<<endl;
}