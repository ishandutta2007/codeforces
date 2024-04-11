#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
long long dx[maxn],dy[maxn],x1,y1,x2,y2,n,a,b,c,u,v,g;
char s[maxn];
int main(){
    scanf("%lld %lld %lld %lld",&x1,&y1,&x2,&y2);
    scanf("%lld",&n);
    scanf("%s",s+1);
    for(int i=1;i<=n;i++){
        dx[i]=dx[i-1],dy[i]=dy[i-1];
        if(s[i]=='U')
            dy[i]++;
        else if(s[i]=='D')
            dy[i]--;
        else if(s[i]=='L')
            dx[i]--;
        else if(s[i]=='R')
            dx[i]++;
    }
    long long l=0,r=1e18,ans=-1,mid;
    while(l<=r){
        mid=(l+r)>>1;
        a=(mid/n);
        u=x1+(a*dx[n]);
        v=y1+(a*dy[n]);
        b=mid%n;
        u+=(dx[b]);
        v+=(dy[b]);
        g=abs(x2-u)+abs(y2-v);
        if(g<=mid){
            ans=mid;
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    printf("%lld\n",ans);
}