#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[501][501],ma[501],mi[501];
signed main(){
    int n,m;
    cin>>n>>m; 
    int t=sqrt((signed)n);
    memset(mi,0x7f,sizeof(mi));
                                                                                                                        memset(ma,0x80,sizeof(ma));
    while(t*(t+1)<n)t++;
    for(int x=1;x<=t+1;x++)
    for(int y=1;y<=t&&(x-1)*t+y<=n;y++)
    cin>>a[x][y];
    for(int x=1;x<=t+1;x++,a[x][0]=a[x-1][t])
    for(int y=1,z;y<=t&&(x-1)*t+y<=n;y++)
    cin>>z,a[x][y]-=z,a[x][y]=-a[x][y],a[x][y]+=a[x][y-1],ma[x]=max(ma[x],a[x][y]),mi[x]=min(mi[x],a[x][y]);
    while(m--)
    {
        int l,r;
        cin>>l>>r;
        int x1=(l-1)/t+1,x2=(r-1)/t+1;
        int y1=l-(x1-1)*t,y2=r-(x2-1)*t;
        //cout<<x1<<','<<y1<<','<<x2<<','<<y2<<','<<a[x1][y1-1]<<','<<a[x2][y2]<<endl;
        if(a[x2][y2]-a[x1][y1-1]!=0)cout<<-1<<endl;
        else
        if(x1!=x2){
                                                                                                                        int ans=-10000000000000000,mni=10000000000000000;
            for(int x=y1;x<=t;x++)
            ans=max(ans,a[x1][x]),mni=min(mni,a[x1][x]);
            for(int x=1;x<=y2;x++)
            ans=max(ans,a[x2][x]),mni=min(mni,a[x2][x]);
            for(int x=x1+1;x<=x2-1;x++)
            ans=max(ans,ma[x]),mni=min(mni,mi[x]);
            if(mni-a[x1][y1-1]<0)cout<<-1<<endl;
            else cout<<ans-a[x1][y1-1]<<endl;
        }
        else{
                                                                                                                        int ans=-10000000000000000,mni=10000000000000000;
            for(int x=y1;x<=y2;x++)
            ans=max(ans,a[x1][x]),mni=min(mni,a[x1][x]);
            if(mni-a[x1][y1-1]<0)cout<<-1<<endl;
            else cout<<ans-a[x1][y1-1]<<endl;
        }
    }
}