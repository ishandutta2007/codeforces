#include <bits/stdc++.h>
using namespace std;
#define N 1000005
#define LIM 1000005
#define ll long long
#define pb push_back
#define gc() (P1==P2 && (P2=(P1=buf)+fread(buf,1,LIM,stdin),P1==P2)?EOF:*P1++)
const int INF=1e9;char *P1,*P2,buf[LIM];
int n,a1[N],a2[N];ll s1,s2,s3;map<ll,int> nw1,nw2,nw3;
int w1[N],w2[N],ps1[N],ps2[N],rt1[N],rt2[N],tg1[N],tg2[N],dp1[N],dp2[N],dp3[N];
vector<int> z1[N],z2[N];
int rd()
{
    int res=0;bool fl=0;char c=0;while(!isdigit(c)) fl|=c=='-',c=gc();
    while(isdigit(c)) res=res*10+(c-48),c=gc();return fl?-res:res;
}
int f1(int x) {return dp1[x]+tg1[rt1[x]];}
int f2(int x) {return dp2[x]+tg2[rt2[x]];}
int merge1(int x,int y)
{
    if(z1[x].size()>z1[y].size()) swap(x,y);
    for(auto i:z1[x]) dp1[i]+=tg1[x]-tg1[y],rt1[i]=y,z1[y].pb(i);
    tg1[x]=0;tg1[y]+=tg1[x];z1[x].clear();return y;
}
int merge2(int x,int y)
{
    if(z2[x].size()>z2[y].size()) swap(x,y);
    for(auto i:z2[x]) dp2[i]+=tg2[x]-tg2[y],rt2[i]=y,z2[y].pb(i);
    tg2[x]=0;tg2[y]+=tg2[x];z2[x].clear();return y;
}
int main()
{
    n=rd();for(int i=0;i<=n;++i) w1[i]=w2[i]=ps1[i]=ps2[i]=i;
    for(int i=1;i<=n;++i) a1[i]=rd();for(int i=1;i<=n;++i) a2[i]=rd();
    nw1[0]=nw2[0]=nw3[0]=0;z1[0].pb(0);z2[0].pb(0);
    for(int i=1,p1,p2,h1=0,h2=0,l1,r1,l2,r2,mid1,mid2,t1,t2,t3;i<=n;++i)
    {
        p1=ps1[i];p2=ps2[i];l1=l2=0;r1=r2=i-1;
        s1+=a1[i];t1=nw1.count(s1)?nw1[s1]:-1;nw1[s1]=i;
        s2+=a2[i];t2=nw2.count(s2)?nw2[s2]:-1;nw2[s2]=i;
        s3+=a1[i]+a2[i];t3=nw3.count(s3)?nw3[s3]:-1;nw3[s3]=i;
        while(h1<=t1) p1=merge1(p1,ps1[h1++]);w1[p1]=i;ps1[i]=p1;++tg1[p1];
        while(h2<=t2) p2=merge2(p2,ps2[h2++]);w2[p2]=i;ps2[i]=p2;++tg2[p2];
        while(l1<=r1) {mid1=(l1+r1)/2;if(f2(i-1)>f2(mid1)) l1=mid1+1;else r1=mid1-1;}
        while(l2<=r2) {mid2=(l2+r2)/2;if(f1(i-1)>f1(mid2)) l2=mid2+1;else r2=mid2-1;}
        dp3[i]=max(max(f1(i-1)+(l2<=t2),f2(i-1)+(l1<=t1)),(~t3?dp3[t3]+1:0));
        dp1[i]=dp2[i]=dp3[i];if(f1(i-1)<dp1[i]) l2=i;if(f2(i-1)<dp2[i]) l1=i;
        dp1[i]-=tg1[ps1[l1]];rt1[i]=ps1[l1];z1[ps1[l1]].pb(i);
        dp2[i]-=tg2[ps2[l2]];rt2[i]=ps2[l2];z2[ps2[l2]].pb(i);
    }printf("%d\n",dp3[n]);return 0;
}