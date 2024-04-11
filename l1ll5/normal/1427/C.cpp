#include <bits/stdc++.h>
#define N 200005
#define ll long long
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
#define inf 1000000000
int T;
int n,r,ans;
struct zgz{
    int x,y,t;
}a[N];
int f[N];
int s[N];
int cal(const zgz &a,const zgz &b){
    return abs(a.x-b.x)+abs(a.y-b.y);
}
int main()
{
    r=read(),n=read()+1;
    a[1].x=1,a[1].y=1,a[1].t=0;
    for(int i=1;i<=n+1;i++) f[i]=-inf;
    f[1]=0;
    for(int i=2;i<=n;i++) a[i].t=read(),a[i].x=read(),a[i].y=read();


    for(int i=2;i<=n;i++){
        for(int j=i-1;j>=i-2550;j--){
            if(j<=0) break ;
            if(cal(a[i],a[j])<=a[i].t-a[j].t){
            //    cerr<<i<<' '<<j<<' '<<f[j]<<endl;
                f[i]=max(f[i],f[j]+1);
            }
        }
        int t=i-2550;
        if(t>0)
        f[i]=max(f[i],s[t]+1);

        s[i]=max(s[i],s[i-1]);
        ans=max(ans,f[i]);
    }
    cout<<ans<<endl;
}