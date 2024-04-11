#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<vector>
#include<math.h>
#include<stdlib.h>
using namespace std;

int n,m;
long long h[100010],p[100010];

inline long long ab(long long x){return x>0?x:-x;}
inline long long mn(long long x,long long y){return x>y?y:x;}

bool check(long long x)
{
    int i,now=0;
    for(i=0;i<n;i++){
        long long t = p[now];
        while(1){
            long long tmp = p[now];
            long long k = mn(ab(h[i]-tmp)+ab(tmp-t),ab(h[i]-t)+ab(tmp-t));
            if(k>x)break;
            now++;
            if(now==m)return true;
        }
    }
    return false;
}

int main()
{
    //freopen("input.txt","r",stdin);
    scanf("%d%d",&n,&m);
    int i;
    for(i=0;i<n;i++)scanf("%lld",h+i);
    for(i=0;i<m;i++)scanf("%lld",p+i);
    long long st=0,en=1e16,mi,ans=0;
    while(st<=en){
        mi=(st+en)>>1;
        if(check(mi))en=mi-1,ans=mi;
        else st = mi+1;
    }
    printf("%lld",ans);
    return 0;
}