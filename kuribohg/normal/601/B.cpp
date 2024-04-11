#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
const int MAXN=100010;
const int INF=1000000000;
int n,Q,tot,top;
LL a[MAXN],c[MAXN],p[MAXN];
LL l[MAXN],r[MAXN];
LL Sta[MAXN];
int main()
{
    scanf("%d%d",&n,&Q);
    for(int i=1;i<=n;i++) scanf("%I64d",&a[i]);
    for(int i=1;i<n;i++) c[i]=abs(a[i+1]-a[i]);
    while(Q--)
    {
        int L,R;
        scanf("%d%d",&L,&R);
        if(L==R) {puts("0");continue;}
        tot=0;
        for(int i=L;i<R;i++) p[++tot]=c[i];
        p[0]=INF,p[tot+1]=INF,top=0;
        for(int i=1;i<=tot;i++)
        {
            while(top&&p[Sta[top]]<p[i]) r[Sta[top]]=i-1,top--;
            Sta[++top]=i;
        }
        for(int i=1;i<=tot;i++)
            if(!r[i]) r[i]=tot;
        top=0;
        for(int i=tot;i>=1;i--)
        {
            while(top&&p[Sta[top]]<=p[i]) l[Sta[top]]=i+1,top--;
            Sta[++top]=i;
        }
        for(int i=1;i<=tot;i++)
            if(!l[i]) l[i]=1;
        top=0;
        LL ans=0;
        for(int i=1;i<=tot;i++)
            ans+=p[i]*(r[i]-i+1)*(i-l[i]+1);
        printf("%I64d\n",ans);
        for(int i=1;i<=tot;i++) l[i]=0,r[i]=0;
    }
    return 0;
}