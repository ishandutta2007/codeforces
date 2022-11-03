
 #include<bits/stdc++.h>
using namespace std;
const int N=200005;
typedef long long ll;
int n;int x,y;
char s[N];
int upx,upy;
int sumx[N],sumy[N];
inline int check(int num)
{
    for(int i=1;i<=n-num+1;i++)
    {
        int j=i+num-1,tx,ty;
        tx=x-upx+sumx[j]-sumx[i-1],ty=y-upy+sumy[j]-sumy[i-1];
        if(abs(tx)+abs(ty)<=num&&(num-abs(tx)-abs(ty))%2==0) return 1;
    }
    return 0;
}
int main()
{
    scanf("%d%s%d%d",&n,s+1,&x,&y);
    for(int i=1;i<=n;i++)
    {
        sumx[i]=sumx[i-1],sumy[i]=sumy[i-1];
        if(s[i]=='U') upy++,sumy[i]++;
        else if(s[i]=='D') upy--,sumy[i]--;
        else if(s[i]=='R') upx++,sumx[i]++;
        else upx--,sumx[i]--;
    }
    if(upx==x&&upy==y) {printf("0");return 0;}
    int l=0,r=n;int mid,ans=-1;
    while(l<=r)
    {
        mid=l+r>>1;
        if(check(mid)) r=mid-1,ans=mid;
        else l=mid+1;
    }
    printf("%d",ans);
    return 0;
}