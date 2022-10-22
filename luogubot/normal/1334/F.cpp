#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a),i##END=(b);i<=i##END;i++)
#define Rof(i,b,a) for(int i=(b),i##END=(a);i>=i##END;i--)
#define go(u) for(int i=head[u];i;i=nxt[i])
char buf[(1<<21)+5],*p1,*p2;
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
#define ll long long
using namespace std;
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*f;
}
const int N=5e5+10;
int n,a[N],p[N],m,b[N],id[N<<1],lst[N<<1];
ll sum[N<<1],f[N],g[N];
inline void gmin(ll &a,ll b){(a>b)&&(a=b);}
signed main(){//fdsf
	n=read();For(i,1,n)a[i]=read();For(i,1,n)p[i]=read();a[n+1]=n+1,n++;
	m=read();For(i,1,m)b[i]=read();b[m+1]=n,m++;
	For(j,0,m-1){id[b[j]]=2*j;For(i,b[j]+1,b[j+1]-1)id[i]=2*j+1;}id[b[m]]=2*m;
	For(i,1,n)g[i]=g[i-1]+min(p[i],0);
	For(i,0,n)a[i]=id[a[i]];memset(lst,-1,sizeof lst),f[0]=lst[0]=0;
	For(i,1,n){
		f[i]=5e18;
		if(!(a[i]&1)){
			if(a[i]){
				int x=lst[a[i]-2];
				if(~x)gmin(f[i],f[x]+((i>=1)?g[i-1]:0)-g[x]+sum[a[i]]+sum[a[i]-1]);
			}int x=lst[a[i]];
			if(~x)gmin(f[i],f[x]+g[i]-g[x]);
		}lst[a[i]]=i;
		if(p[i]>0)sum[a[i]]+=p[i];
	}
	if(f[n]<1e18)cout<<"YES\n"<<f[n]<<endl;
	else puts("NO");
	return 0;
}