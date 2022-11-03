#include <bits/stdc++.h>
using namespace std;
// val=(n-1)sum(ai^2+bi^2)+2sum(aiaj+bibj)
//    =(n-2)sum(ai^2+bi^2)+(sum(a))^2+(sum(b))^2
//    =(n-2)sum(ai^2+bi^2)+((sum(a)+sum(b))^2+(sum(a)-sum(b))^2)/2
typedef long long ll;
const int maxn=105;
const int maxa=105;
const int maxs=maxa*maxn;
int n,a[maxn],cur;
ll s2,sab;
bool vis[2][maxs];
int main()
{
    int T,i,j,b,s;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        s2=sab=0;
        for(i=0;i<n;i++) scanf("%d",&a[i]),sab+=a[i],s2+=a[i]*a[i];
        for(i=0;i<n;i++) scanf("%d",&b),sab+=b,s2+=b*b,a[i]-=b;
        for(i=0,s=0;i<n;i++) (s+=(a[i]=abs(a[i])));
        cur=0;
        for(i=0;i<=s;i++) vis[cur][i]=!i;
        for(i=0;i<n;i++)
        {
            cur^=1;
            for(j=0;j<=s;j++) vis[cur][j]=0;
            for(j=0;j<=s;j++)
                if(vis[cur^1][j])
                    vis[cur][j+a[i]]=vis[cur][abs(j-a[i])]=1;
        }
        for(i=0;i<=s && !vis[cur][i];i++);
        printf("%lld\n",s2*(n-2ll)+(sab*sab+i*(ll)i)/2);
    }
    return 0;
}