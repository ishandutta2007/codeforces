// Problem: C. Cloud Computing
// Contest: Codeforces - 2018-2019 ICPC, NEERC, Southern Subregional Contest (Online Mirror, ACM-ICPC Rules, Teams Preferred)
// URL: https://codeforces.com/contest/1070/problem/C
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//And in that light,I find deliverance.
#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include<bits/stdc++.h>
#define ll long long
using namespace std; 
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int ls[10000003],rs[10000003];
ll val[10000003];
ll sum[10000003];
int cnt=1;
void update(int L,int R,int p,int v,int id)
{
    if(L==R)
    {
    	val[id]+=v;
    	sum[id]+=1ll*p*v;
        return ;
    }
    int mid=(L+R)>>1;
    if(p<=mid) 
    	(!ls[id])&&(ls[id]=++cnt),update(L,mid,p,v,ls[id]);
    else 
    	(!rs[id])&&(rs[id]=++cnt),update(mid+1,R,p,v,rs[id]);
    val[id]=val[ls[id]]+val[rs[id]];
    sum[id]=sum[ls[id]]+sum[rs[id]];
    return ;
}
ll query(int L,int R,int p,int id)
{
	if(!p) return 0;
    if(L==R) 
    {
    	return 1ll*L*p;
    }
    int mid=(L+R)>>1;
    if(val[ls[id]]>=p) return query(L,mid,p,ls[id]);
    else return sum[ls[id]]+query(mid+1,R,p-val[ls[id]],rs[id]);
}
struct node
{
	int t,p,v;
	bool operator<(const node&o)const
	{
		return t<o.t;
	}
}a[400003];
signed main()
{
    int n=read(),m=read(),k=read();
    int N=0;
    for(int i=1; i<=k; ++i) 
    {
    	int x=read(),y=read(),z=read(),w=read();
    	a[++N]=(node){x,w,z},
    	a[++N]=(node){y+1,w,-z};
    }
    a[++N]=(node){n+1,0,0};
    sort(a+1,a+N+1);
    ll ans=0;
    for(int i=1; i<N; ++i)
    {
    	update(1,1000000,a[i].p,a[i].v,1);
    	if(a[i].t!=a[i+1].t)
    	{
    		ll qwq=0;
    		if(val[1]<=m) qwq=sum[1];
    		else qwq=query(1,1000000,m,1);
    		ans+=qwq*(a[i+1].t-a[i].t);
    	}
    }
    printf("%lld\n",ans);
	return 0;
}